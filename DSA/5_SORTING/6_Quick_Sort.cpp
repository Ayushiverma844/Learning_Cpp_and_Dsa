//  Problem Statement:
// Title: Sort an Array using Quick Sort (with Vectors)

// Objective:
// Write a C++ program to sort a list of integers using the Quick Sort algorithm. Use recursion and partitioning logic, and store the data in a vector. The pivot should be chosen as the last element during partitioning.

// Requirements:

// Use a vector<int> to store an unsorted array of integers.

// Implement the Quick Sort algorithm with:

// A partition() function to place the pivot in its correct position.

// A QuickSort() function to recursively sort subarrays.

// Display the array before and after sorting.

// Constraints:

// The vector must contain at least one integer.

// Sorting should be done in ascending order.

// Sample Input/Output:

// Given:==>
// 12 31 35 8 32 17

// After sorting:==>
// 8 12 17 31 32 35

#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int st, int end) {
    // Choose the last element as pivot
    int idx = st - 1, pivot = arr[end]; // pivot is the value at the end index

    for (int j = st; j < end; j++) {
        // Compare elements with pivot
        if (arr[j] < pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    // Place pivot at the correct position
    swap(arr[end], arr[idx + 1]); // Now pivot is at idx + 1
    return idx + 1; // Return pivot index
}

void QuickSort(vector<int>& arr, int st, int end) {
    if (st < end) {
        // Call partition function which gives us correct index of pivot
        int pivIdx = partition(arr, st, end);

        // Recursive call for the left half
        QuickSort(arr, st, pivIdx - 1);

        // Recursive call for the right half
        QuickSort(arr, pivIdx + 1, end);
    }
}

int main() {
    vector<int> arr = {12, 31, 35, 8, 32, 17};

    cout << "Given:==>\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    // Call Quick sort 
    QuickSort(arr, 0, arr.size() - 1);

    // Print sorted array
    cout << "After sorting:==>\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
