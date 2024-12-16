//Kadane's Algorithm =>
// Kadane's Algorithm is an efficient method used to find the maximum sum subarray within a 
//one-dimensional array of numbers, where the subarray can be of any length, including a single 
//element. This problem is also known as the Maximum Subarray Problem.

// Problem Definition:
// Given an array of integers, you need to find the contiguous subarray (with at least one number) 
//that has the largest sum.

// Key Idea:
// Kadane’s Algorithm works by iterating through the array and maintaining a running sum of the 
//subarray. If the running sum becomes negative at any point, it is reset to zero because any 
//negative running sum would decrease the sum of the next subarray. The maximum sum is updated as
// you iterate.

#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubarray(vector<int>& num){
    int currSum = 0 , maxSum = INT_MIN ;

    for(int val : num){
        currSum += val ;
        maxSum = max(currSum,maxSum);

     // If the current sum becomes negative, reset it to 0 and start fresh  
        if(maxSum<0){
            currSum = 0;
        }
    }

    return maxSum ;  
}

int main() {

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum is: " << maxSubarray(arr) << endl;
    return 0;
}

