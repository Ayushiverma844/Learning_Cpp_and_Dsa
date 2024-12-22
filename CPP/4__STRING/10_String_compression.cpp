//String Compression

// Given an array of characters chars, compress it using the following algorithm:
// Begin with an empty string s. For each group of consecutive repeating characters in chars:
// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
// After you are done modifying the input array, return the new length of the array.
// You must write an algorithm that uses only constant extra space.


// Example 1:
// Input: chars = ["a","a","b","b","c","c","c"]
// Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

// Example 2:
// Input: chars = ["a"]
// Output: Return 1, and the first character of the input array should be: ["a"]
// Explanation: The only group is "a", which remains uncompressed since it's a single character.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int idx = 0;  // Position where the next compressed character will go.

    for (int i = 0; i < n;) {
        char ch = chars[i];  // Current character to check for repetition
        int count = 0;

        // Count how many times the current character repeats
        while (i < n && chars[i] == ch) {
            count++;
            i++;
        }

        // Place the character itself at the current index
        chars[idx++] = ch;

        // If count > 1, add the count as a string of digits
        if (count > 1) {
            string str = to_string(count);  // Convert count to string
            for (char dig : str) {
                chars[idx++] = dig;  // Add each digit of the count
            }
        }
    }

    // Resize the vector to the correct length after compression
    chars.resize(idx);

    return idx;  // Return the new size of the compressed vector
}

int main() {
    // Example usage
    vector<char> chars = {'a', 'a', 'b', 'b', 'b', 'c', 'c', 'a', 'a'};
    int newLength = compress(chars);

    // Output the compressed characters
    cout << "Compressed string length: " << newLength << endl;
    for (int i = 0; i < newLength; ++i) {
        cout << chars[i];
    }
    cout << endl;

    return 0;
}
