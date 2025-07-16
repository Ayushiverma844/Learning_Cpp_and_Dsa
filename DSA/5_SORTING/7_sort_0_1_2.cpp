// Problem Statement:

// Given an array arr consisting only of 0s, 1s, and 2s, sort the array in ascending order in-place without using any sorting algorithm.

// Constraints:

// 1 <= N <= 10^6

// 0 <= arr[i] <= 2

// Input:

// The first line contains an integer N — the size of the array.

// The second line contains N space-separated integers (only 0s, 1s, and 2s).

// Output:

// Print the sorted array in ascending order.

// Example:

// Input:
// 6
// 0 2 1 2 0 1

// Output:
// 0 0 1 1 2 2

#include <iostream>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // Using hashmap to count frequency of 0, 1, and 2
        unordered_map<int, int> freq;
        
        for(int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }
        
        int i = 0;
        
        // Placing all 0's
        while(freq[0] != 0) {
            arr[i] = 0;
            i++;
            freq[0]--;
        }
        
        // Placing all 1's
        while(freq[1] != 0) {
            arr[i] = 1;
            i++;
            freq[1]--;
        }
        
        // Placing all 2's
        while(freq[2] != 0) {
            arr[i] = 2;
            i++;
            freq[2]--;
        }
    }
};

// Driver code for testing
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    Solution ob;
    ob.sort012(arr);
    
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout << endl;
    
    return 0;
}
