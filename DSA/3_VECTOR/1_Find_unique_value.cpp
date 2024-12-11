//Leetcode question

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