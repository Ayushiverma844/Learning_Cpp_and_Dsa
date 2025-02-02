#include <iostream>
using namespace std;

    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') {
                if (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                    ans -= 1;
                else
                    ans += 1;
            } 
            else if (s[i] == 'V') {
                ans += 5;
            } 
            else if (s[i] == 'X') {
                if (i + 1 < n && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                    ans -= 10;
                else
                    ans += 10;
            } 
            else if (s[i] == 'L') {
                ans += 50;
            } 
            else if (s[i] == 'C') {
                if (i + 1 < n && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                    ans -= 100;
                else
                    ans += 100;
            } 
            else if (s[i] == 'D') {
                ans += 500;
            } 
            else if (s[i] == 'M') {
                ans += 1000;
            }
        }

        return ans;
    }

int main() {
    Solution sol;
    
    // Test cases
    cout << "III = " << sol.romanToInt("III") << endl;         // Output: 3
    cout << "IV = " << sol.romanToInt("IV") << endl;           // Output: 4
    cout << "IX = " << sol.romanToInt("IX") << endl;           // Output: 9
    cout << "LVIII = " << sol.romanToInt("LVIII") << endl;     // Output: 58
    cout << "MCMXCIV = " << sol.romanToInt("MCMXCIV") << endl; // Output: 1994
    
    return 0;
}
