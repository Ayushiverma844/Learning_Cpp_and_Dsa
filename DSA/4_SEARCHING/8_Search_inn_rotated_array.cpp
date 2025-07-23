#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int l = 0, h = arr.size() - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (arr[mid] == key) {
                return mid;
            }

            // If left half is sorted
            if (arr[l] <= arr[mid]) {
                if (arr[l] <= key && key < arr[mid]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // Else right half must be sorted
            else {
                if (arr[mid] < key && key <= arr[h]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return -1; // Element not found
    }
};

// Driver code
int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2}; // Rotated sorted array
    int key = 0;

    Solution sol;
    int index = sol.search(arr, key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found in array." << endl;

    return 0;
}
