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