#include <iostream>
#include <string>
#include <algorithm> // for reverse
using namespace std;

// Solution class with addBinary function
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string ans = "";
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += s1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += s2[j] - '0';
                j--;
            }

            ans += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());

        // Optional: remove leading zeroes (not needed for most binary sum problems)
        while (ans.length() > 1 && ans[0] == '0') {
            ans.erase(0, 1);
        }

        return ans;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    string s1, s2;

    // Sample input
    cout << "Enter first binary string: ";
    cin >> s1;
    cout << "Enter second binary string: ";
    cin >> s2;

    string result = sol.addBinary(s1, s2);
    cout << "Sum of binary strings: " << result << endl;

    return 0;
}
