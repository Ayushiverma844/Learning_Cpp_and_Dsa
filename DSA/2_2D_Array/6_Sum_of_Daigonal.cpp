//  Problem Statement: Sum of Both Diagonals in a Square Matrix
// Write a C++ program to calculate the sum of both the primary and secondary diagonals of a square matrix. If an element lies on both diagonals (i.e., the center element in an odd-sized matrix), it should be counted only once in the total sum.

// 📥 Input:
// A square matrix of size n x n (in the code, fixed to 3x3).

// 📤 Output:
// Print the total sum of both diagonals.

// 🧾 Example:

// 11  22  33  
// 10  20  30  
// 1   2   3
// Primary Diagonal: 11, 20, 3
// Secondary Diagonal: 33, 20, 1
// (Center element 20 is shared but counted only once)

// Output:
// Sum of Diagonals = 88


#include<iostream>
#include<algorithm>
using namespace std;

int sumOfDaigonal(int arr[][3], int n) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // Primary diagonal
            if (i == j) {
                sum += arr[i][j];
            }
            // Secondary diagonal, but only if it's not already counted
            else if (j == n - 1 - i) {
                sum += arr[i][j];
            }
        }
    }

    return sum;
}

int main() {
    int arr[3][3] = {{11, 22, 33}, {10, 20, 30}, {1, 2, 3}};   

    cout << "Sum of Diagonals = " << sumOfDaigonal(arr, 3);

    return 0;
}
