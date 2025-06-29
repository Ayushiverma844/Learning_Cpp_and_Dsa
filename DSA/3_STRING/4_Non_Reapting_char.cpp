#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    // Function to find the first non-repeating character
    char nonRepeatingChar(string &s) {
        unordered_map<char, int> frq;

        // Step 1: Count frequency of each character
        for (int i = 0; i < s.length(); i++) {
            frq[s[i]]++;
        }

        // Step 2: Find the first character with frequency 1
        for (int i = 0; i < s.length(); i++) {
            if (frq[s[i]] == 1) {
                return s[i];
            }
        }

        // If no non-repeating character found
        return '$';
    }
};

// Driver code
int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    Solution obj;
    char result = obj.nonRepeatingChar(str);

    if (result == '$') {
        cout << "No non-repeating character found." << endl;
    } else {
        cout << "First non-repeating character: " << result << endl;
    }

    return 0;
}
