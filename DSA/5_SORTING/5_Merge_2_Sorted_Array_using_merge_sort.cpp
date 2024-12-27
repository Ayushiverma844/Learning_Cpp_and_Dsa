// Merge Sorted Array

// You are given two integer arrays A and B, sorted in non-decreasing order, and two integers m and n, representing the number of elements in A and B respectively.
// Merge A and B into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function, but instead be stored inside the array A. To accommodate this, A has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:
// Input: A = [1,2,3,0,0,0], m = 3, B = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from A.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int idx = m + n - 1, i = m - 1, j = n - 1;

    // Merge the two arrays from the end
    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[idx--] = A[i--];
        } else {
            A[idx--] = B[j--];
        }
    }

    // If elements remain in B, copy them
    while (j >= 0) {
        A[idx--] = B[j--];
    }
}

int main() {
    // Example arrays (sorted)
    vector<int> arr = {1, 3, 5, 7};  // Array A
    vector<int> brr = {2, 4, 6};     // Array B

    // Get the sizes of the arrays
    int m = arr.size();
    int n = brr.size();

    // Resize arr to accommodate the elements of brr
    arr.resize(m + n);

    // Call the merge function
    merge(arr, m, brr, n);

    // Print the merged array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}