#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to check if we can place k cows with minimum distance 'dis'
    bool check(vector<int> &stalls, int k, int dis) {
        int prev = stalls[0];
        int cnt = 1; // First cow placed

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - prev >= dis) {
                cnt++;
                prev = stalls[i];
            }
        }
        return cnt >= k;
    }

    // Main function to find maximum minimum distance
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int low = 1;
        int high = stalls.back() - stalls[0];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(stalls, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

// Driver Code
int main() {
    int n, k;
    cin >> n >> k; // n = number of stalls, k = number of cows

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    Solution obj;
    cout << obj.aggressiveCows(stalls, k) << endl;

    return 0;
}
