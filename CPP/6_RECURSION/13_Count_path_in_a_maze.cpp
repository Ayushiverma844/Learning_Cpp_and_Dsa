// Question: Counting Paths in a Maze
// You are given an n x n grid where the top-left corner is at (0, 0) and the bottom-right corner is
// at (n-1, n-1). You are allowed to move only right or down at each step. Your task is to calculate 
//the number of distinct paths from the top-left corner to the bottom-right corner.

// Write a recursive function countPathMaze(int n, int i, int j) that takes the following parameters:

// n: the size of the grid (the grid is n x n).
// i: the current row index (starting from 0).
// j: the current column index (starting from 0).
// The function should return the total number of ways to reach the bottom-right corner from the
// current position (i, j)


#include<iostream>
using namespace std;

int countPathMaze(int n , int i , int j){
    
    // Base Case: if we have reached the destination
    if(i == n-1 && j == n-1){
        return 1;
    }

    // Base Case: if we have overshot the destination
    if(i >= n || j >=n ){
        return 0;
    }

    // Try all possible ways

    return countPathMaze(n,i+1,j) + countPathMaze(n,i,j+1);
   
}

int main(){
    
    int n;

    cout<<"Enter no of boxes: ";
    cin>>n;

    // Call the function and get the result

    int result = countPathMaze(n , 0 ,0);

    cout << "There are " << result << " ways to reach the end . " <<endl;
    
    return 0;
}