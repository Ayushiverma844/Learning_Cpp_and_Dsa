#include<iostream>
using namespace std;

int main()
{
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    int arr[r][c];

    cout << "Enter the elements of the array:\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    // Spiral order print

    int row_start = 0;  // starting row
    int row_end = r - 1;   // ending row
    int col_start = 0;  // starting column
    int col_end = c - 1;   // ending column

    cout << "Spiral Order of the array is: ";
    while(row_start <= row_end && col_start <= col_end) {
        // Print the top row (row_start)
        for(int i = col_start; i <= col_end; i++) {
            cout << arr[row_start][i] << " ";
        }
        row_start++;

        // Print the right column (col_end)
        for(int i = row_start; i <= row_end; i++) {
            cout << arr[i][col_end] << " ";
        }
        col_end--;

        // Print the bottom row (row_end)
        if(row_start <= row_end) {
            for(int i = col_end; i >= col_start; i--) {
                cout << arr[row_end][i] << " ";
            }
            row_end--;
        }

        // Print the left column (col_start)
        if(col_start <= col_end) {
            for(int i = row_end; i >= row_start; i--) {
                cout << arr[i][col_start] << " ";
            }
            col_start++;
        }
    }

    cout << endl;
    return 0;
}
