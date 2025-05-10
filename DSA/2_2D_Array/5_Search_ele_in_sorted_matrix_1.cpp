
//  Problem Title: Search in a Row and Column-Wise Sorted Matrix
// Problem Statement:

// You are given a 2D matrix of size n x m where each row and each column is sorted in increasing order. Write a program to efficiently search for a given target value in the matrix.

// If the target value is present in the matrix, print "element found."
// Otherwise, print "Element does not exit."

// Input Format:

// First line: Two integers n and m — number of rows and columns.

// Next n × m integers: Elements of the matrix.

// Last line: An integer target — the value to search for.

// Constraints:

// 1 ≤ n, m ≤ 1000

// -10⁵ ≤ matrix[i][j], target ≤ 10⁵

// The matrix is sorted such that:

// Each row is sorted from left to right.

// Each column is sorted from top to bottom.

// Output Format:

// Print "element found." if the target is in the matrix.

// Otherwise, print "Element does not exit."

// Example Input:
// 3 4
// 1 4 7 11
// 2 5 8 12
// 3 6 9 16
// 5

// Example Output:
// element found.

               

#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout << "Enter size of row and coloumn: ";
    cin >> n>>m;
    int a[n][m];   
    bool found = false;

    // Store elements in 1st matrix
    cout << "Enter values of 1st matrix: ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int target;
    cout<<"Enter target value to search: " ;
    cin>>target;

    int r=0 , c=m-1;   // Start from top-right corner

    while(r<n && c>=0){
        if(a[r][c] == target){
            found = true;
            break;  // Exit the loop once the target is found
        }
        else if(a[r][c] > target){
            c--;   // Move left if the target is smaller
        }else{
            r++;   // Move down if the target is larger
        }
    }
    
      // Output the result
       if(found){
        cout<<"element found.";
       }else{
        cout<<"Element does not exit.";
       }
    return 0; 
}
