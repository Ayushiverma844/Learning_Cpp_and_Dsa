#include <iostream>
#include <algorithm>  // for sort
using namespace std;

class Solution {
  public:
    // Function to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Sort both strings
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        // Compare sorted strings
        return s1 == s2;
    }
};

int main() {
    string str1, str2;
    
    // Example input: listen silent
    cin >> str1 >> str2;
    
    Solution obj;
    if(obj.areAnagrams(str1, str2)) {
        cout << "Yes, they are anagrams" << endl;
    } else {
        cout << "No, they are not anagrams" << endl;
    }

    return 0;
}
