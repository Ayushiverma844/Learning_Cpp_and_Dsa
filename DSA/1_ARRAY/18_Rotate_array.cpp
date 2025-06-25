#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;  // to handle cases where d > n
        vector<int> temp(n);

        int i = d, k = 0;

        // Copy elements from d to end
        while (i < n) {
            temp[k++] = arr[i++];
        }

        // Copy elements from beginning to d
        i = 0;
        while (i < d) {
            temp[k++] = arr[i++];
        }

        // Copy back to original array
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};

// For local testing
int main() {
    int n, d;
    cin >> n >> d;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    obj.rotateArr(arr, d);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
