// Problem Statement:
// Given an array of integers nums, count how many positive and negative numbers it contains. The goal is to return the maximum count between the positive and negative numbers. Zero is neither considered positive nor negative.

// Example:
// Input:
// nums = [-3, -2, -1, 0, 1, 2, 3]

// Output:
// 3

// Explanation:
// The array contains 3 negative numbers (-3, -2, -1) and 3 positive numbers (1, 2, 3). The function returns 3 since the count of both positive and negative numbers is the same.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int neg = 0;
            int pos = 0;
            int max_count = 0;
            for(int i=0;i<nums.size();i++){
                // 0 is neither  positive nor negative.
                if(nums[i] < 0){
                    // no is negative
                 neg++;
                }
                else if(nums[i] > 0){
                    // no is postive
                    pos++;
                }
            }
            return max(neg,pos);;
        }
    };

    int main() {
        vector<int> nums = {-3, -2, -1, 0, 1, 2, 3}; // Example input
    
        Solution obj; 
        int result = obj.maximumCount(nums);
    
        cout << "Maximum count of positive or negative numbers: " << result << endl;
    
        return 0;
    }