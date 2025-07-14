

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
