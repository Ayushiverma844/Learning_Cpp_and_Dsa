#include <iostream>
using namespace std;

// User function template for C++
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        vector<int> temp;
        int n = arr.size();
        int i = 1, j = 0;

        while(i <= arr[n - 1]) {
            if(j < n && arr[j] == i) {
                j++;
            } else {
                temp.push_back(i);
            }
            i++;
        }

        // If still not enough missing elements
        while(temp.size() < k) {
            temp.push_back(i);
            i++;
        }

        return temp[k - 1];
    }
};

// Driver code (GeeksforGeeks format)
int main() {
    int n, k;
    cin >> n >> k;  // Input size of array and k

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];  // Input array elements

    Solution ob;
    cout << ob.kthMissing(arr, k) << endl;

    return 0;
}
