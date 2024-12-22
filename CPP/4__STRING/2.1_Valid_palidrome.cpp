// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

//Example 2:
//Input: ka?n?a?k
//output: true
// Explanation: "kanak" is a palindrome.


#include<iostream>
#include<algorithm>
using namespace std;

bool isAlphanumeric(char ch) {
    // Check if character is alphanumeric (either a digit or a letter)
    return (ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z');
}

bool isPalindrome(string s) {
    int st = 0, end = s.length() - 1;

    while (st < end) {
        // Skip non-alphanumeric characters from the start
        if (!isAlphanumeric(s[st])) {
            st++;
            continue;
        }
        // Skip non-alphanumeric characters from the end
        if (!isAlphanumeric(s[end])) {
            end--;
            continue;
        }

        // Compare characters ignoring case
        if (tolower(s[st]) != tolower(s[end])) {
            return false;
        }

        // Move both pointers towards the center
        st++;
        end--;
    }

    return true;
}

int main() {
    string  String;
    cout << "Enter a string: ";
    getline(cin , String);

    if (isPalindrome(String)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
