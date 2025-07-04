// Problem Statement:
// Given an array of positive integers and an integer k, find the maximum length of a contiguous subarray whose sum is exactly equal to k.

//  Input:
// An integer array arr[] of size n.

// An integer value k representing the target sum.

//  Output:
// The length of the longest subarray whose sum is exactly k.

//  Example:
// Input:
// arr[] = {4, 1, 1, 1, 2, 3, 5}
// k = 5

// Output:
// Maximum size subarray of sum 5 is 4
// Explanation:
// The subarray {1, 1, 1, 2} adds up to 5 and has the maximum length of 4.



#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum size of the subarray with sum equal to k
int maxInSubarray(int arr[], int size, int k) {
    int i = 0, j = 0;
    long int sum = 0;
    int maxLength = 0;

    while (j < size) {
        // Add the current element to the sum
        sum += arr[j];

        // If the sum exceeds k, move the left pointer to reduce the sum
        while (sum > k && i <= j) {
            sum -= arr[i];
            i++;
        }

        // If the sum equals k, update the maximum length
        if (sum == k) {
            maxLength = max(maxLength, j - i + 1);
        }

        // Move the right pointer to explore the next element
        j++;
    }
    
    return maxLength;
}

int main() {
    int arr[7] = {4, 1, 1, 1, 2, 3, 5};
    int k;

    // Input sum 
    cout << "Enter sum: ";
    cin >> k;

    // Call the function and get the result
    int result = maxInSubarray(arr, 7, k);

    // Output the result
    cout << "Maximum size subarray of sum " << k << " is " << result << endl;

    return 0;
}
