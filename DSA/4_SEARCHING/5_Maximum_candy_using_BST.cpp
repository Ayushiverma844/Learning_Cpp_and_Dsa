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
