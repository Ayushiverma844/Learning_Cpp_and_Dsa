// Search a 2D Matrix

// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.
 
// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool searchInRow(vector<vector<int>>& matrix, int target, int row) {
    int n = matrix[0].size();
    int st = 0, end = n - 1;

    while(st <= end) {
        int mid = st + (end - st) / 2;

        if(target == matrix[row][mid]) {
            return true;
        }
        else if(target > matrix[row][mid]) {
            // right
            st = mid + 1;
        }
        else {
            // left
            end = mid - 1;
        }
    }

    return false;
}

bool search(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();   // no of rows
    int n = matrix[0].size();  // no of columns

    int stRow = 0, endRow = m - 1;

    while(stRow <= endRow) {
        int mid = stRow + (endRow - stRow) / 2;

        if(target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
            // found the row ==> now apply BS on this row
            return searchInRow(matrix, target, mid);
        }
        else if(target > matrix[mid][n - 1]) {
            // downwards ==> in terms of BS right
            stRow = mid + 1;
        }
        else {
            // upwards ==> in terms of BS left
            endRow = mid - 1;
        }
    }

    return false;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target;
    cout << "Enter the target value to search: ";
    cin >> target;

    if(search(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}
