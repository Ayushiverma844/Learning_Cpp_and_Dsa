//  Problem Statement: Recursive Binary Search in a Sorted Array
// Write a C++ program to implement binary search using recursion. The program should search for a given element in a sorted array. If found, return its index; otherwise, return -1.

// Input:
// An integer n representing the size of the array.

// n sorted integers (in increasing order).

// An integer target to search in the array.

// Output:
// If the target is found, display its index.

// If not found, print a message indicating so.

// Example:
// Input:
// Enter size of array: 6  
// Enter elements: 2 4 6 8 10 12  
// Enter value to search: 10
// Output:
// Element found at index: 4

#include<iostream>
using namespace std;

// Function for binary search
int BinarySearch(int arr[], int size, int target,int st,int end) {
  
    while(st <= end) {
        int mid = (st + end) / 2;  // mid index
        
        if(arr[mid] == target) {
            return mid;  // found the key, return index
        } else if(arr[mid] > target) {
          //recurssive call
            BinarySearch(arr,size,target,st,mid-1);  // search in the left half
        } else {
          //recurssive call
            BinarySearch(arr,size,target,mid+1,end);  // search in the right half
        }
    }
    return -1;  // target not found
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    int key;
    cout << "\nEnter value to search: ";
    cin >> key;
    
    int result = BinarySearch(arr, n, key,0,n-1);
    
    if(result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    
    return 0;
}