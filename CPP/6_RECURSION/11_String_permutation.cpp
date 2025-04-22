// Problem Statement:
// Title: Generate All Permutations of a String

// Description:
// Write a recursive function that prints all possible permutations of a given string. A permutation is an arrangement of all the characters of the string in any possible order.

// Input:
// A string s consisting of unique uppercase characters (e.g., "ABC").

// Output:
// Print all the permutations of the string, each on a new line.

// Example Input:
// ABC

// Example Output:
// ABC
// ACB
// BAC
// BCA
// CAB
// CBA


#include<iostream>
#include<string>
using namespace std;

void permutation(string s , string ans){
    
    if(s.length()==0){     //Base case
        cout<<ans<<endl;
        return;
    }

    for(int i=0 ; i<s.length(); i++){

      char ch = s[i];     //fixing character
      string ros = s.substr(0,i) + s.substr(i+1);   //string befor fixed character + string after fixed char

         permutation(ros,ans+ch);     // recursive call
    }

}

int main(){
    string s = "ABC";

    //call function

    permutation(s, " ");

    return 0;
}