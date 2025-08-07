#include <iostream>
using namespace std;

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());  // Sorting is important for two-pointer approach
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = arr[i] + arr[l] + arr[r];

                if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                } else {
                    // sum == target
                    int e1 = arr[l], e2 = arr[r];

                    if (e1 == e2) {
                        int count = r - l + 1;
                        ans += (count * (count - 1)) / 2;
                        break; // all elements between l and r are the same
                    } else {
                        int count1 = 0, count2 = 0;

                        while (l < r && arr[l] == e1) {
                            l++;
                            count1++;
                        }

                        while (r >= l && arr[r] == e2) {
                            r--;
                            count2++;
                        }

                        ans += count1 * count2;
                    }
                }
            }
        }

        return ans;
    }
};

// Driver code (for testing)
int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5};
    int target = 8;

    Solution obj;
    cout << "Total Triplets = " << obj.countTriplets(arr, target) << endl;

    return 0;
}
