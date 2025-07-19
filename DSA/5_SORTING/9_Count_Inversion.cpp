// Problem Statement:

// You are given an array of integers. Your task is to count the number of inversions in the array.

// An inversion is a pair of indices (i, j) such that:

// i < j, and

// arr[i] > arr[j]

// Write a program to return the total number of such inversion pairs in the array.

// Input:

// The first line contains a single integer n — the number of elements in the array.

// The second line contains n space-separated integers — the elements of the array.

// Output:

// Output a single integer — the total number of inversion pairs in the array.

// Constraints:

// 1 ≤ n ≤ 10^5

// 1 ≤ arr[i] ≤ 10^9

#include <iostream>
using namespace std;

class Solution {
public:
    // Merge two sorted halves and count inversions
    int merge(vector<int> &arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        int ans = 0;

        vector<int> left(n1);
        vector<int> right(n2);

        // Copy data to temp arrays
        for (int i = 0; i < n1; i++) {
            left[i] = arr[l + i];
        }
        for (int i = 0; i < n2; i++) {
            right[i] = arr[m + 1 + i];
        }

        int i = 0, j = 0, k = l;

        // Merge the two halves and count inversions
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                ans += (n1 - i); // Count inversions
                j++;
            }
            k++;
        }

        // Copy remaining elements if any
        while (i < n1) {
            arr[k++] = left[i++];
        }
        while (j < n2) {
            arr[k++] = right[j++];
        }

        return ans;
    }

    // Recursive function to count inversions
    int count(vector<int> &arr, int l, int r) {
        int ans = 0;
        if (l < r) {
            int m = l + (r - l) / 2;
            ans += count(arr, l, m);
            ans += count(arr, m + 1, r);
            ans += merge(arr, l, m, r);
        }
        return ans;
    }

    // Main function to call
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return count(arr, 0, n - 1);
    }
};

// Driver code
int main() {
    int n;
    cin >> n;  // Input size of array
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Input elements
    }

    Solution ob;
    int result = ob.inversionCount(arr);
    cout << result << endl;

    return 0;
}
