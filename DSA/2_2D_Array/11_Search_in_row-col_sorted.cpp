#include <iostream>
#include <vector>
using namespace std;

// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int r = mat.size();
        int c = mat[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == x) return true;
                else if (mat[i][j] > x) break;  // Optimization: Stop checking the rest of the row
            }
        }
        return false;
    }
};

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));

    cout << "Enter matrix elements (row-wise sorted):\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> mat[i][j];

    int x;
    cout << "Enter element to search: ";
    cin >> x;

    Solution ob;
    bool found = ob.matSearch(mat, x);

    if (found)
        cout << x << " is present in the matrix.\n";
    else
        cout << x << " is not present in the matrix.\n";

    return 0;
}
