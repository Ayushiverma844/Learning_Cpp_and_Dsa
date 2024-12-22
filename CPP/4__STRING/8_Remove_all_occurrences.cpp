// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.
// A substring is a contiguous sequence of characters in a string.

// Example 1:

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".


#include<iostream>
#include<string>
using namespace std;

string removeOccurrences(string s,string part){

    while(s.length()>0 && s.find(part) < s.length()) // Loop until 'part' is found in 's'
       {
          s.erase(s.find(part),part.length());   // Erase the first occurrence of 'part'
       }
    return s;  // Return the modified string
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    string result = removeOccurrences(s, part);   //all continuous abc will be removed
    cout << result << endl;          //output = dab
    return 0;
}