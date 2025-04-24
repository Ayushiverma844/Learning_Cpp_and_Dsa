// Problem Statement:
// Check if an Array is Sorted using Recursion

// Write a C++ program that takes a vector of integers as input and determines whether the array is sorted in non-decreasing order using a recursive function.

// Implement a recursive function isSorted() that takes a vector of integers and its size as input.

// The function should return true if the array is sorted in non-decreasing order, otherwise return false.

// In the main() function, initialize a sample array and call the recursive function to check if the array is sorted.

// Print "Array is sorted" if the array is in order, else print "Array is not sorted".

// Example Output:
// Array is sorted



#include<iostream>
#include<vector>

using namespace std;

bool isSorted(vector<int>arr,int n){
    if(n==0 || n==1){
        return true;
    }

    return  arr[n-1] >= arr[n-2] && isSorted(arr,n-1); 
}


int main(){
    vector<int>arr ={1,2,3,4,5};

    if(isSorted(arr,arr.size())){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }

    return 0;
}