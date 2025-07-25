#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        vector<int> temp;
        int i = 0, j = 0;
        
        // Merge two sorted arrays
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                temp.push_back(a[i]);
                i++;
            } else {
                temp.push_back(b[j]);
                j++;
            }
        }

        // Push remaining elements of a[]
        while (i < a.size()) {
            temp.push_back(a[i]);
            i++;
        }

        // Push remaining elements of b[]
        while (j < b.size()) {
            temp.push_back(b[j]);
            j++;
        }

        // Return the k-th element (1-based index)
        return temp[k - 1];
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    // Function call
    int result = obj.kthElement(a, b, k);

    // Output
    cout << "The " << k << "-th element is: " << result << endl;

    return 0;
}
