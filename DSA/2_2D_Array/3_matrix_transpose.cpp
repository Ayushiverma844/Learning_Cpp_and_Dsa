// Problem Statement:

// Title: Transpose of a Square Matrix

// Description:
// Write a C++ program to input a square matrix of size n × n from the user, compute its transpose, and print the transposed matrix.
// The transpose of a matrix is obtained by swapping elements across its main diagonal (i.e., arr[i][j] becomes arr[j][i]).

// Input:

// An integer n representing the size of the square matrix.

// n × n integers representing the elements of the matrix.

// Output:

// Print the transposed matrix.

// Example:
// Input:
// Enter size: 3  
// Enter values:  
// 1 2 3  
// 4 5 6  
// 7 8 9  

// Output:
// Transposed matrix:  
// 1 4 7  
// 2 5 8  
// 3 6 9

#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n][n];   // square matrix

    // Store elements
    cout << "Enter values: ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Transpose the matrix
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {  // Start from i+1 to avoid swapping back
            // Swap arr[i][j] with arr[j][i]
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // Print the transposed matrix
    cout << "Transposed matrix: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0; 
}
