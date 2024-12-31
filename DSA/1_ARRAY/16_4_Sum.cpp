// 4Sum

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.


// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
 


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();
    
    // Sort the array to make it easier to handle duplicates and use two-pointer technique
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n-3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;  // Skip duplicate for the first number
        }

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;  // Skip duplicate for the second number
            }

            int p = j + 1, q = n - 1;
            while (p < q) {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];
                
                if (sum > target) {
                    q--;
                } else if (sum < target) {
                    p++;
                } else {
                    // Found a quadruplet
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;

                    // Skip duplicates for the third and fourth numbers
                    while (p < q && nums[p] == nums[p - 1]) {
                        p++;
                    }
                    while (p < q && nums[q] == nums[q + 1]) {
                        q--;
                    }
                }
            }
        }
    }
    
    return ans;
}


int main() {
    vector<int> nums = {1, -1, 2, 3, -2};
    int target = 0;

    // Call the fourSum function
    vector<vector<int>> result = fourSum(nums, target);

    // Print the result
    for (const auto& quad : result) {
        cout << "[";
        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i != quad.size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}