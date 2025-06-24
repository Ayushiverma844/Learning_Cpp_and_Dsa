#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n, 0); // Temporary vector filled with zeros
        int k = 0;

        // Copy non-zero elements to temp
        for(int i = 0; i < n; i++) {
            if(arr[i] != 0) {
                temp[k] = arr[i];
                k++;
            }
        }

        // Copy elements back to original array
        for(int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};

// Optional: Test driver code
int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    Solution obj;
    
    cout << "Original Array: ";
    for(int val : arr) cout << val << " ";
    cout << endl;

    obj.pushZerosToEnd(arr);

    cout << "After Pushing Zeros to End: ";
    for(int val : arr) cout << val << " ";
    cout << endl;

    return 0;
}
