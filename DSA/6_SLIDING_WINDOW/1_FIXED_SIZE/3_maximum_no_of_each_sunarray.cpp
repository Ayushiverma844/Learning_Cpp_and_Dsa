//  Problem Statement: Maximum in Each Subarray of Size k
//  Objective:
// Write a program to find the maximum element in every contiguous subarray of size k from a given array of integers.

//  Problem Description:
// Given an array of integers and a positive integer k, your task is to slide a window of size k across the array and print the maximum element in each window (subarray).

//  Input:
// An array arr[] of integers (in the given code, it's hardcoded as {1, 2, 3, 4, -5, 6}).

// An integer k representing the size of the subarray (input from the user).

//  Output:
// A list of integers representing the maximum element from each subarray of size k.

//  Example:
// Input:

// arr[] = {1, 2, 3, 4, -5, 6}
// k = 3
// Output:
// Maximum of each subarray: 3 4 4 6

// Constraints:
// 1 ≤ k ≤ size of the array

// The array contains both positive and negative integers.



#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum of each subarray of size k
vector<int> maxInSubarray(int arr[], int size, int k) {
    int i = 0, j = 0;
    vector<int> ans;

    while (j < size) {
        // If the current window size is less than k, expand the window
        if (j - i + 1 < k) {
            j++;
        }
        // If the window size is exactly k, process the window
        else if (j - i + 1 == k) {
            int maximum = arr[i]; // Start with the first element of the window

            // Find the maximum value in the current window
            for (int idx = i; idx <= j; idx++) {
                if (arr[idx] > maximum) {
                    maximum = arr[idx];
                }
            }

            // Store the maximum in the result
            ans.push_back(maximum);

            // Slide the window
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    int arr[6] = {1, 2, 3, 4, -5, 6};
    int k;

    // Input size of the subarray
    cout << "Enter size of subarray: ";
    cin >> k;

    // Call the function and get the result
    vector<int> result = maxInSubarray(arr, 6, k);

    // Output the result
    cout << "Maximum of each subarray: ";
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
