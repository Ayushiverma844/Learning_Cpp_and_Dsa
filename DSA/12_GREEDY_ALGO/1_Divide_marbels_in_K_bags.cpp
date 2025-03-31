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
