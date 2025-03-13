//Problem Statement:
// Write a C++ program to generate and print all possible subsets (power set) of a given set of integers.

// Input:
// An integer n, representing the number of elements in the set.
// n space-separated integers representing the elements of the set.
// Output:
// All possible subsets of the given set, including the empty subset {}. Each subset should be printed on a new line.
// Constraints:
// n should be a positive integer. If n is zero or negative, display an error message and terminate the program.
// Example:

// Input:
// Enter size: 3  
// Enter elements: 1 2 3  

// Output:
// {}  
// 1  
// 2  
// 1 2  
// 3  
// 1 3  
// 2 3  
// 1 2 3  

#include<iostream>
using namespace std;

void subset(int arr[], int size) {
    // Iterate through all possible subsets
    for (int i = 0; i < (1 << size); i++) {
        bool isEmpty = true; // Flag to check if the subset is empty

        // Check each bit of i to decide if arr[j] should be in the subset
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) {
                cout << arr[j] << " "; // Print the element
                isEmpty = false; // If we print at least one element, it's not empty
            }
        }

        // Print a new line for the next subset
        if (isEmpty) {
            cout << "{}"; // Print "{}" for empty subsets
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    // Handle cases where n might be zero or negative
    if (n <= 0) {
        cout << "Invalid size. Exiting program." << endl;
        return 1;
    }

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << endl;
    subset(arr, n);

    return 0;
}

    