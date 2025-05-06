// Problem Statement:

// Title: Read and Print a 2-D Array

// Description:
// Write a C++ program to read a two-dimensional array (matrix) from the user and then print its elements. The user will provide the number of rows and columns, followed by the elements of the matrix.

// Input:

// Two integers r and c representing the number of rows and columns.

// r × c integers representing the elements of the matrix.

// Output:

// Print each element of the matrix on a new line.

// Example:

// Input:
// Enter no or row & colomn: 2 2
// enter no 1
// enter no 2
// enter no 3
// enter no 4

// Output:
// 1
// 2
// 3
// 4


#include<iostream>
using namespace std;

int main()
{
    int r,c;
 cout<<"Enter no or row & colomn: ";
    cin>>r>>c;
    int arr[r][c];
    for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
             cout<<("enter no ");
               cin>>arr[i][j];
           }
       }
    for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
             cout<<"\n"<<arr[i][j];
           }
       }
   return 0;
}