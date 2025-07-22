#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr) {
        // Initialize result with the first element
        int res = arr[0];

        // Traverse the array to find the minimum
        for(int i = 1; i < arr.size(); i++) {
            res = min(res, arr[i]);
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n; // Input size of the array
    vector<int> arr(n);

    // Input array elements
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    int result = obj.findMin(arr);

    // Output the result
    cout << result << endl;

    return 0;
}
