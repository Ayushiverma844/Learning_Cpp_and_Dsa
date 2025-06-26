#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int myAtoi(char *s) {
        int res = 0;
        int i = 0;
        int sign = 1;

        // Skip leading whitespaces
        while (s[i] == ' ') {
            i++;
        }

        // Handle optional sign
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Convert number and handle overflow
        while (s[i] >= '0' && s[i] <= '9') {
            int dig = s[i] - '0';

            // Check for overflow before multiplying/resizing
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && dig > 7)) {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            res = res * 10 + dig;
            i++;
        }

        return res * sign;
    }
};

// For local testing
int main() {
    Solution sol;
    char str1[] = "   -42";
    char str2[] = "4193 with words";
    char str3[] = "words and 987";
    char str4[] = "-91283472332";

    cout << sol.myAtoi(str1) << endl;  // Output: -42
    cout << sol.myAtoi(str2) << endl;  // Output: 4193
    cout << sol.myAtoi(str3) << endl;  // Output: 0
    cout << sol.myAtoi(str4) << endl;  // Output: INT_MIN

    return 0;
}
