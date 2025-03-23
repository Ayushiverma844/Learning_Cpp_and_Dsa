// Problem Statement:

// Given a string of lowercase English characters, the task is to find the most frequent character in the string and print both the character and its frequency. If multiple characters have the same highest frequency, the program should print the lexicographically smallest character among them.

// Input:
// A string str of lowercase English characters (with a length between 1 and 1000).

// Output:
// Print the frequency of the most frequent character and the character itself, separated by a space.

// Example:
// For the string "abhskaaasjdnczff", the output should be:
// 4 a
// In this example, the character 'a' appears the most times (4 times), so it is printed along with its frequency.

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str = "abhskaaasjdnczff";
 
    int freq[26] = {0};  // Initialize all elements to 0

    // Count the frequency of each character in the string
    for(int i = 0; i < str.size(); i++) {
        freq[str[i] - 'a']++;  // Convert char to index and increment frequency
    }

    char ans = 'a';
    int maxF = 0;

    // Find the character with the highest frequency
    for(int i = 0; i < 26; i++) {
        if(freq[i] > maxF) {
            maxF = freq[i];
            ans = i + 'a';  // Convert index back to character
        }
    }

    // Output the result
    cout << maxF << " " << ans << endl;

    return 0;
}
