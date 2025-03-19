//Problem Statement:
You are given a string consisting of words separated by spaces. Your task is to find the longest word in the string and return it, along with its length. If there are multiple words of the longest length, return the first one encountered.

Input:
A string arr consisting of words separated by spaces. The string may contain leading or trailing spaces and can include multiple spaces between words.

Output:
The longest word in the string.

The length of the longest word.

Approach:
Traverse through the string to identify words. A word is defined as a sequence of non-space characters.

Track the length of the current word as you encounter each character.

Whenever a space or the end of the string is encountered, check if the current word is the longest one encountered so far. If so, update the longest word and its length.

After processing the string, output the longest word and its length.

Example:
Input:

csharp
Copy
Enter a string: This is an example string with multiple words
Output:

arduino
Copy
Longest word: multiple
Length of longest word: 8

#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr;
    cout << "Enter a string: ";
    getline(cin, arr);  // Read the entire line

    int i = 0;
    int currlen = 0, maxlen = 0;  // current length and maximum length
    int st = 0, maxst = 0;  // start index of current word and start index of longest word

    // Traverse through the string
    while (i <= arr.length()) {
        if (arr[i] == ' ' || arr[i] == '\0') {  // End of a word
            if (currlen > maxlen) {
                maxlen = currlen;  // Update max length
                maxst = st;         // Update start of the longest word
            }
            currlen = 0;  // Reset current length
            st = i + 1;   // Move the start to the next word
        } else {
            currlen++;  // Increment the current word length
        }

        if (arr[i] == '\0') {  // End of string
            break;
        }
        i++;
    }
