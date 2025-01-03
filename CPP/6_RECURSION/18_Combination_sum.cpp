                          //Combination Sum

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency
//  of at least one of the chosen numbers is different.
// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Example 1:
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:
// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]


#include<iostream>
#include<set>
#include<vector>
using namespace std;

void helper(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& comb) {
    // Base case: when we either go out of bounds or the target becomes negative.
    if (tar == 0) {
        ans.push_back(comb); // Add the valid combination
        return;
    }
    if (idx == arr.size() || tar < 0) {
        return; // No valid combination possible from here
    }

    // Explore the current index (use the element at arr[idx])
    comb.push_back(arr[idx]);
    helper(arr, idx, tar - arr[idx], ans, comb); // Multiple use case
    comb.pop_back(); // Backtrack

    // Explore without using the current index
    helper(arr, idx + 1, tar, ans, comb);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    vector<int> comb;
    helper(arr, 0, target, ans, comb);
    return ans;
}


int main() {
    vector<int> arr={2,3,6,7};
    int target = 7;

    // Get the combinations
    vector<vector<int>> result = combinationSum(arr, target);

    // Output the result
    cout << "Combinations that sum to " << target << " are:\n";
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
