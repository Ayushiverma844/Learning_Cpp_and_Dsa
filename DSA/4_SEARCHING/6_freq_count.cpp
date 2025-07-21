#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        unordered_map<int, int> freq;
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

        if (freq.find(target) != freq.end()) {
            return freq[target];
        }

        return 0;
    }
};

int main() {
    int n, target;
    cin >> n;  // Size of array
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;  // Element whose frequency we want

    Solution obj;
    int result = obj.countFreq(arr, target);
    cout << result << endl;

    return 0;
}
