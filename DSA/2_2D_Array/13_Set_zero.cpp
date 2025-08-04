#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();       // number of rows
        int m = mat[0].size();    // number of columns

        // Create row and column flags
        vector<bool> row(n, false);
        vector<bool> col(m, false);

        // Step 1: Mark the rows and columns that should be zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        // Step 2: Update the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};

// ✅ Helper function to print matrix
void printMatrix(const vector<vector<int>> &mat) {
    for (const auto &row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// ✅ Main function
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    Solution obj;
    cout << "Original Matrix:\n";
    printMatrix(mat);

    obj.setMatrixZeroes(mat);

    cout << "\nMatrix after setting zeroes:\n";
    printMatrix(mat);

    return 0;
}
