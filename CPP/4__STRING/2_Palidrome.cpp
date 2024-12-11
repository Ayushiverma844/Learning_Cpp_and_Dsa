// Write a program to check if a string or number is a palindrome.
// Example:
// Input: string = "radar"
// Output: Palindrome
// Explanation: "radar" reads the same backward as forward.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    bool isPalindrome = true;
    int length = input.length();

    // Check characters from the start and end
    for (int i = 0; i < length / 2; i++) {
        if (input[i] != input[length - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "Its a Palindrome" << endl;
    } else {
        cout << "Its Not a palindrome" << endl;
    }

    return 0;
}