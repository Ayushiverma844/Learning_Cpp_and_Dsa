// find the most frequent character in a string and print both the character and its frequency.

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
