//Problem Statement:
// You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.

// Divide the marbles into the k bags according to the following rules:

// No bag is empty.
// If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
// If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
// The score after distributing the marbles is the sum of the costs of all the k bags.

// Return the difference between the maximum and minimum scores among marble distributions.

 
// Example 1:

// Input: weights = [1,3,5,1], k = 2
// Output: 4
// Explanation: 
// The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1) = 6. 
// The distribution [1,3],[5,1], results in the maximal score of (1+3) + (5+1) = 10. 
// Thus, we return their difference 10 - 6 = 4.


// Example 2:

// Input: weights = [1, 3], k = 2
// Output: 0
// Explanation: The only distribution possible is [1],[3]. 
// Since both the maximal and minimal score are the same, we return 0.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0; // Only one partition means no difference

        vector<long long> pairSums;
        
        // Compute adjacent pair sums
        for (int i = 0; i < n - 1; i++) {
            pairSums.push_back(weights[i] + weights[i + 1]);
        }

        // Sort the pair sums to extract min and max `k-1` partitions
        sort(pairSums.begin(), pairSums.end());

        long long maxSum = 0, minSum = 0;
        for (int i = 0; i < k - 1; i++) {
            minSum += pairSums[i];                 // Smallest k-1 sums
            maxSum += pairSums[n - 2 - i];         // Largest k-1 sums
        }

        return maxSum - minSum;
    }
};

int main() {
    Solution sol;
    vector<int> weights = {1, 3, 5, 1}; // Example case
    int k = 2;
    cout << sol.putMarbles(weights, k) << endl;
    return 0;
}
