#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        if(s1.length() != s2.length()) return false;
        
        string temp = s2+s2;
        
        int pos = temp.find(s1);
        if(pos >= 0) return true;
        else return false;
    }
};

int main() {
    Solution solution;

    // Test case 1: Strings are rotations of each other
    string s1 = "abcde", s2 = "cdeab";
    cout << "Test case 1: " << (solution.areRotations(s1, s2) ? "Yes" : "No") << endl;

    // Test case 2: Strings are not rotations of each other
    string s3 = "abcd", s4 = "abdc";
    cout << "Test case 2: " << (solution.areRotations(s3, s4) ? "Yes" : "No") << endl;

    // Test case 3: Strings are identical, so they are trivially rotations
    string s5 = "hello", s6 = "hello";
    cout << "Test case 3: " << (solution.areRotations(s5, s6) ? "Yes" : "No") << endl;

    return 0;
}