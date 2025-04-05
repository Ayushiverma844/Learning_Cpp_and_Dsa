// Problem Statement:
// You are given an integer array nums. The XOR sum of a subset is defined as the bitwise XOR of all the elements in that subset. Return the sum of the XOR sum of all possible subsets of nums.

// Example 1:

// Input: nums = [1, 3]
// Output: 6
// Explanation: The subsets of nums are:
// [], [1], [3], [1,3]
// The XOR sum of the subsets are:
// 0, 1, 3, 2
// The sum is 0 ^ 1 ^ 3 ^ 2 = 6.

// Example 2:
// Input: nums = [5, 1, 6]
// Output: 28

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        // Iterate over all possible subsets (2^n subsets)
        for (int i = 0; i < (1 << n); ++i) {
            int subsetXor = 0;
            
            // For each subset, determine the elements that are included
            for (int j = 0; j < n; ++j) {
                // Check if the j-th element is in the current subset
                if (i & (1 << j)) {
                    subsetXor ^= nums[j]; // XOR the element
                }
            }
            
            // Add the XOR result of this subset to the total sum
            sum += subsetXor;
        }
        
        return sum;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 3};
    cout << "XOR sum of all subsets of [1, 3]: " << solution.subsetXORSum(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {5, 1, 6};
    cout << "XOR sum of all subsets of [5, 1, 6]: " << solution.subsetXORSum(nums2) << endl;

    return 0;
}
