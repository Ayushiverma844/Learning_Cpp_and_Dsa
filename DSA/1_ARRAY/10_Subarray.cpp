// Problem Statement:

// Title: Print All Subarrays of an Array

// Description:
// Write a C++ program to input an array of integers from the user and then print all possible subarrays of the array. A subarray is a contiguous part of an array. For an array of size n, the total number of subarrays will be n * (n + 1) / 2.

// Input:

// An integer n representing the size of the array.

// n integers representing the elements of the array.

// Output:

// Print all subarrays, one per line.

// Example:

// Input:
// enter size of array : 3
// Enter
// 1 2 3

// Output:
// 1
// 1 2
// 1 2 3
// 2
// 2 3
// 3



#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter size of array : ";
    cin>>n;

    int a[n];

    //store elements in array
    cout<<"Enter\n";
     for(int i=0;i<n;i++){
        cin>>a[i];
     }

//The total number of subarrays in an array of size N is N * (N + 1) / 2.
     for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<a[k]<<" ";
            }
            cout<<"\n";
        }
     }

     return 0;
}