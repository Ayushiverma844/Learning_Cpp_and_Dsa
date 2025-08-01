#include <iostream>
using namespace std;

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();        // number of rows
        int m = mat[0].size();     // number of columns
        
        int i = 0, j = m - 1;      // start from top-right corner

        while(i < n && j >= 0) {
            if(mat[i][j] == x)
                return true;
            else if(mat[i][j] > x)
                j--;  // move left
            else
                i++;  // move down
        }

        return false;  // if not found
    }
};

int main() {
    Solution obj;
    vector<vector<int>> mat = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int x = 5;

    if(obj.searchRowMatrix(mat, x))
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
