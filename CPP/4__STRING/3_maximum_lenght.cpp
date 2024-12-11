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
