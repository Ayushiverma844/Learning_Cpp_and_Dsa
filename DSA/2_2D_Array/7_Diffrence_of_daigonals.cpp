//  Problem Statement: Absolute Diagonal Difference in a Square Matrix
// Write a C++ program that calculates the absolute difference between the sums of the primary diagonal and the secondary diagonal of a square matrix of size n x n.

//  Input:
// An integer n representing the size of the square matrix.

// n rows of n integers each, representing the matrix elements.

// Output:
// Print the absolute difference between the primary and secondary diagonal sums.

// Example:
// Input:

// Enter matrix size (n x n): 3  
// Enter matrix elements row-wise:  
// 11 2 4  
// 4 5 6  
// 10 8 -12  
// Primary Diagonal: 11, 5, -12 → sum = 4
// Secondary Diagonal: 4, 5, 10 → sum = 19
// Absolute Difference: |4 - 19| = 15

// Output:
// Diagonal Difference: 15

#include<iostream>
#include<vector>
#include<cmath>   //for absolute diffrence
using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int sum_d1 =0;
    int sum_d2 =0;
    int n = arr.size();
    
        for (int i = 0; i < n; i++) {
        sum_d1 += arr[i][i];         // Primary diagonal
        sum_d2 += arr[i][n - 1 - i]; // Secondary diagonal
    }
       
  return abs(sum_d1 - sum_d2); // Absolute difference
}

int main() {
    int n;
    cout << "Enter matrix size (n x n): ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    cout << "Enter matrix elements row-wise:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Diagonal Difference: " << diagonalDifference(arr) << endl;
    return 0;
}