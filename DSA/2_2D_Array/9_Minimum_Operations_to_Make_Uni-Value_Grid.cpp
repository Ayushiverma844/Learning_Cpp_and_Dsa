// Problem Statement: Minimum Operations to Make Grid Elements Equal
// You are given a 2D grid of size m x n where each cell contains an integer. You are also given an integer x.

// In one operation, you can increase or decrease any grid element by x (i.e., grid[i][j] += x or grid[i][j] -= x).

// Your task is to determine the minimum number of operations required to make all elements of the grid equal.

// If it is impossible to make all elements equal using the given operation, return -1.

// Input Format:
// An integer m representing the number of rows in the grid.

// An integer n representing the number of columns in the grid.

// An m x n matrix containing integers.

// An integer x representing the step value.

// Output Format:
// An integer representing the minimum number of operations required to make all elements equal.

// If it's not possible, return -1.


class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> temp;
            
            // Flattening the 2D grid into a 1D array
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++) {
                    temp.push_back(grid[i][j]);
                }
            }
    
            // Sorting the array
            sort(temp.begin(), temp.end());
    
            // Finding the median element
            int mid = temp[temp.size() / 2];
    
            int count = 0;
    
            // Converting all elements to the median using steps of 'x'
            for(int num : temp) {
                int diff = abs(num - mid);
                if (diff % x != 0) return -1; // If it's not a multiple of x, return -1
                count += diff / x;
            }
    
            return count;
        }
    };

    int main() {
        int m, n, x;
        cout << "Enter rows and columns of grid: ";
        cin >> m >> n;
    
        vector<vector<int>> grid(m, vector<int>(n));
    
        cout << "Enter grid elements:\n";
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
    
        cout << "Enter value of x: ";
        cin >> x;
    
        Solution obj;
        int result = obj.minOperations(grid, x);
    
        cout << "Minimum operations required: " << result << endl;
    
        return 0;
    }
    