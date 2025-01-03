// Problem Statement:
// You are given a square maze represented by an n x n grid, where each cell in the grid is either
// open (represented by 1) or blocked (represented by 0). You start from the top-left corner (0, 0) 
//and your goal is to reach the bottom-right corner (n-1, n-1). You can only move to cells that are 
//open (1), and you are allowed to move down or right from any given cell.

// The task is to find a path from the start (0, 0) to the destination (n-1, n-1) such that you only
// move through open cells, and you can only move in a right or down direction.


#include<iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n) {
    // Check if (x, y) is inside the bounds of the matrix and the cell is 1 (safe)
    return (x < n && y < n && arr[x][y] == 1);
}

bool ratinMaze(int** arr, int x, int y, int n, int **solArr) {
    // Base Case: If we reached the bottom-right corner
    if (x == n-1 && y == n-1) {
        solArr[x][y] = 1;
        return true;
    }

    // If the current position is safe, mark it and try moving
    if (isSafe(arr, x, y, n)) {
        solArr[x][y] = 1;  // Mark the current cell in the solution path

        // Try moving down (x+1, y)
        if (ratinMaze(arr, x + 1, y, n, solArr)) {
            return true;
        }

        // Try moving right (x, y+1)
        if (ratinMaze(arr, x, y + 1, n, solArr)) {
            return true;
        }

        // If neither move worked, unmark the current cell and backtrack
        solArr[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    int n;
    cout << "Size of square matrix: ";
    cin >> n;

    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    cout << "Enter the matrix (0 for blocked, 1 for open):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
     
     cout<<"\n-----------------------------\n";
     
    // Solution matrix initialized with 0
    int **solArr = new int*[n];
    for (int i = 0; i < n; i++) {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            solArr[i][j] = 0;
        }
    }

    // Solve the maze
    if (ratinMaze(arr, 0, 0, n, solArr)) {
        cout << "Solution Path:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists!" << endl;
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
        delete[] solArr[i];
    }
    delete[] arr;
    delete[] solArr;

    return 0;
}
