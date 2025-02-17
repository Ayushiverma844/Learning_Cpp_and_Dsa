// Given an array of integers, for each element in the array, you need to find the next greater element (NGE) that comes after it. If no such greater element exists for an element, return -1 for that element.

// Problem Details:
// You are given an array arr[] of size n containing integers.
// For each element arr[i], you need to find the first greater element to the right of arr[i] in the array. If no greater element exists, set the answer as -1 for that element.
// Input:
// A vector arr[] of size n, where each element represents an integer in the array.
// Output:
// For each element in the array, output the next greater element.

// Example:

// Input:
// arr = {4, 5, 2, 10, 8}

// Output:
// 5 10 10 -1 -1

// Explanation:
// The next greater element for 4 is 5.
// The next greater element for 5 is 10.
// The next greater element for 2 is 10.
// The next greater element for 10 is -1 (no greater element exists after it).
// The next greater element for 8 is -1 (no greater element exists after it).




#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {4, 5, 2, 10, 8};
    //next greater element
    stack<int> s;
    vector<int> ans(arr.size() , 0);

    for(int i = arr.size()-1; i >= 0; i--){
        while(s.size() > 0 && s.top() <= arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(arr[i]);
}

   // print 
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}