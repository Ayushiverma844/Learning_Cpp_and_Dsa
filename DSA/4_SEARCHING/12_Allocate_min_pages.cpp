#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    // Helper function to check if it's possible to allocate books with given limit
    bool check(vector<int> &arr, int k , int limit) {
        int cnt = 1;        // Number of students
        int pagesum = 0;    // Pages currently allocated to one student
        
        for(int i = 0; i < arr.size(); i++) {
            if(pagesum + arr[i] > limit) {
                cnt++;                  // Allocate to next student
                pagesum = arr[i];       // Start new allocation
            } else {
                pagesum += arr[i];      // Add book to current student
            }
        }
        return (cnt <= k);   // Return true if students used ≤ k
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(n < k) {
            return -1;  // Not enough books for each student
        }

        int low = *max_element(arr.begin(), arr.end());  // Minimum limit = max book size
        int high = accumulate(arr.begin(), arr.end(), 0); // Maximum limit = sum of all pages
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(check(arr, k, mid)) {
                ans = mid;
                high = mid - 1;  // Try to minimize
            } else {
                low = mid + 1;   // Increase the limit
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> books = {12, 34, 67, 90}; // Example input
    int students = 2;

    cout << "Minimum number of pages = " << obj.findPages(books, students) << endl;

    return 0;
}
