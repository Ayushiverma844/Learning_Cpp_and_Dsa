// Given a vector of binary strings of length n, find a binary string of length n that is not present in the given list. Construct this new string by flipping the diagonal elements (i.e., nums[i][i]) of the given binary strings.

// Input: A vector of n binary strings, each of length n.
// Output:A new binary string of length n that is different from all given strings.

// Example:
// Input: nums = ["110", "101", "011"]
// Output: "010"
// note: "000", "001","100","111"  is also correct but we need only one of them which not present so choose any one


#include <iostream>
#include <vector>
using namespace std;

// Function to find a different binary string
string findDifferentBinaryString(vector<string>& nums) {
    string ans = "";
    int n = nums.size();
    
    // Constructing the answer by flipping the diagonal elements
    for (int i = 0; i < n; i++) {
        ans += (nums[i][i] == '0') ? '1' : '0'; 
    }
    
    return ans;
}

int main() {
    // Sample input
    vector<string> nums = {"110", "101", "011"};

    // Function call
    string result = findDifferentBinaryString(nums);
    
    // Output the result
    cout << "Different Binary String: " << result << endl;

    return 0;
}
