//Leetcode question

// Problem Statement: Single Number
// You are given a non-empty array of integers nums, where every element appears twice except for one. Find that single one.

// You must implement a solution with linear runtime complexity and use only constant extra space.

// Function Signature:
// int singleNumber(vector<int>& nums);
// Input:
// A vector nums containing integers where every element appears exactly twice, except one element that appears only once.

// Output:
// Return the element that appears only once.

// Example:
// Input:
// nums = [4, 1, 2, 1, 2]

// Output:
// 4

// Explanation:
// Elements 1 and 2 appear twice.

// Element 4 appears only once and should be returned.

// Constraints:
// 1 <= nums.length <= 3 * 10^4

// -3 * 10^4 <= nums[i] <= 3 * 10^4

// Each element in the array appears twice except for one.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int val : nums) {   //[n^0=n]
            ans ^= val;          //[n^n=0]
        }
        return ans;
    }
};

int main() {
    // Example vector with duplicates and one unique number
    vector<int> nums = {4, 1, 2, 1, 2};
    
    // Create an instance of the Solution class
    Solution sol;
    
    // Call the singleNumber function and print the result
    cout << "Unique value = " << sol.singleNumber(nums) << endl;

    return 0;
}