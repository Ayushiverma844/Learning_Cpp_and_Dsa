// Reverse Words in a String

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:
// Input: s = "the sky is blue"
// Output: "blue is sky the"

// Example 2:
// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.


#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

  string reverseWords(string s) {
        int n = s.length();
        string ans = "";
 
        reverse(s.begin(),s.end());

        // Traverse the string from left to right and extract words
        for(int i=0; i<n;i++){
             string word = "";
             while(i<n && s[i] !=' '){
                word += s[i];  // Build the current word
                i++;
             }

             reverse(word.begin() , word.end());

              // Add the word to the result if it's non-empty
             if(word.length()>0){
                ans = ans+ " " + word;  // Add space and place it at the front
             }
        }
        return ans.substr(1);  //start from 1st index to remove space from the start
    }

    int main() {
    string input = "  Hello   World  ";
    cout << reverseWords(input) << endl;
    return 0;
}