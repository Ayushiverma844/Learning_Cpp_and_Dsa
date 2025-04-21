// ✅ Problem Statement:
// Title: Move All 'x' Characters to the End of the String

// Description:
// Write a recursive function that takes a string as input and moves all the characters 'x' present in the string to the end, while maintaining the order of the other characters.

// Input:
// A string s consisting of lowercase English letters.

// Output:
// A new string with all 'x' characters moved to the end of the original string.

// Example:
// Input:  axxbdxcefxhix
// Output: abdcefhixxx


#include <iostream>
using namespace std;

string move_x(string s) {
    if (s.length() == 0) {
        return "";  // Base case: empty string
    }

    char ch = s[0];
    string ans = move_x(s.substr(1));  // Recursive call to process the rest of the string

    if ( ch == 'x') {
        return ans+ch;  
    }

    return ch + ans;  // Otherwise, include ch in the result
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = move_x(s);
    cout << "String after moving all x at the last: " << result << endl;

    return 0;
}
