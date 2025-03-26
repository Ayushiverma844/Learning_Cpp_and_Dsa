

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
    