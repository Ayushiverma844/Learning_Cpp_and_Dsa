#include <iostream>
using namespace std;

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Step 1: Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
        
        // Step 2: Transpose the matrix
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    obj.rotateMatrix(mat);

    // Output rotated matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
