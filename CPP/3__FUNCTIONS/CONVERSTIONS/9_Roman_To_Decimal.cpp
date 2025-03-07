 //Problem Statement:
// Given a Roman numeral as a string, convert it to an integer.

// Roman Numerals:
// Roman numerals are represented by seven different symbols:

// I = 1
// V = 5
// X = 10
// L = 50
// C = 100
// D = 500
// M = 1000

// Roman numeral rules:
// Subtraction Rule: If a smaller numeral appears before a larger numeral, subtract the smaller numeral. For example, "IV" means 4 (5 - 1) and "IX" means 9 (10 - 1).
// Addition Rule: If a numeral appears before or equal to a larger numeral, add the value of the numeral. For example, "VII" means 7 (5 + 1 + 1) and "XIII" means 13 (10 + 1 + 1 + 1).

// Function Signature:
// int romanToInt(string s);
// Input:
// A string s representing a Roman numeral (1 ≤ s.length ≤ 15).
// The Roman numeral string s contains only valid Roman characters: 'I', 'V', 'X', 'L', 'C', 'D', 'M'.
// Output:
// Return an integer that represents the value of the Roman numeral string.

// Example 1:
// Input: s = "III"
// Output: 3

// Example 2:
// Input: s = "IV"
// Output: 4

// Example 3:
// Input: s = "IX"
// Output: 9

// Example 4:
// Input: s = "LVIII"
// Output: 58

// Example 5:
// Input: s = "MCMXCIV"
// Output: 1994

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
