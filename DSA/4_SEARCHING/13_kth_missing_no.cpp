// Problem Statement:

// Given a sorted array arr[] of positive integers and an integer k, your task is to find the k-th missing positive number that is not present in the array.

// Input:
// An integer n representing the size of the array.
// An integer k representing the k-th missing number to find.
// A sorted array arr[] of size n, containing unique positive integers.

// Output:
// Return the k-th missing positive number that does not appear in the array.

// Constraints:
// 1 <= n <= 1000
// 1 <= arr[i] <= 10^4
// 1 <= k <= 1000

// Example:

// Input:
// n = 5, k = 2
// arr = [2, 3, 4, 7, 11]

// Output:
// 5

// Explanation:
// Missing numbers are [1, 5, 6, 8, 9, 10, ...]
// The 2nd missing number is 5.



#include <iostream>
using namespace std;

// User function template for C++
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        vector<int> temp;
        int n = arr.size();
        int i = 1, j = 0;

        while(i <= arr[n - 1]) {
            if(j < n && arr[j] == i) {
                j++;
            } else {
                temp.push_back(i);
            }
            i++;
        }

        // If still not enough missing elements
        while(temp.size() < k) {
            temp.push_back(i);
            i++;
        }

        return temp[k - 1];
    }
};

// Driver code (GeeksforGeeks format)
int main() {
    int n, k;
    cin >> n >> k;  // Input size of array and k

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];  // Input array elements

    Solution ob;
    cout << ob.kthMissing(arr, k) << endl;

    return 0;
}
