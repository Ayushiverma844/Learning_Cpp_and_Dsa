// Move all 'x' at the last of the string

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
