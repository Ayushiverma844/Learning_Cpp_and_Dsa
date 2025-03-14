// Problem Statement:
// You are given an array candies[], where candies[i] represents the number of candies in the i-th pile. There are k children, and you need to distribute the candies among them. Each child must receive the same number of candies.

// Find the maximum number of candies each child can receive such that all candies are divided fairly among the children. If it's not possible to give at least one candy to each child, return 0.

// Example 1:
// Input:
// candies = [5, 8, 6]  , k = 3  
// Output: 5
// Explanation:
// If each child gets 5 candies, we can distribute:
// Pile [5] → 1 child
// Pile [8] → 1 child gets 5, 3 candies remain
// Pile [6] → 1 child gets 5, 1 candy remains
// Total 3 children are served.
// If we try to give 6 candies per child, it's not possible to serve 3 children.
// The maximum candies each child can get is 5.

// Example 2:
// Input:
// candies = [2, 5]  , k = 11  
// Output: 0
// Explanation:
// Total candies = 2 + 5 = 7, but we need at least 11 candies to give each child at least 1 candy.
// So, the answer is 0.



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = 0;
        int max_candies = 0;

        for (int candy : candies) {
            total += candy;
            max_candies = max(max_candies, candy);
        }

        // If total candies are less than k, we can't give at least 1 candy to each child
        if (total < k) return 0;

        int left = 1, right = max_candies, ans = 0;

        // Binary search for the maximum candies per child
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long count = 0;

            // Count how many children can receive at least `mid` candies
            for (int candy : candies) {
                count += (candy / mid);
            }

            if (count >= k) {
                ans = mid;  // Mid is a valid answer
                left = mid + 1;  // Try for a larger number
            } else {
                right = mid - 1;  // Try for a smaller number
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candies = {5, 8, 6};  // Test Case 1
    long long k = 3;
    cout << "Maximum candies per child: " << sol.maximumCandies(candies, k) << endl;

    candies = {2, 5};  // Test Case 2
    k = 11;
    cout << "Maximum candies per child: " << sol.maximumCandies(candies, k) << endl;

    return 0;
}
