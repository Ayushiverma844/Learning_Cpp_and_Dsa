// Problem Statement: Reverse a String Using Recursion
// Objective:
// Write a C++ program to reverse a given string using a recursive approach.

// Requirements:

// Take a string as input from the user.

// Use a recursive function to reverse the string.

// Display the reversed string as output.

// Constraints:

// Do not use loops or inbuilt reverse functions.

// Only recursion should be used to reverse the string.

// Sample Input/Output:
// Input:  Enter string: hello
// Output: Reverse of hello is = olleh


#include<iostream>
#include<string>
using namespace std;

// Function to reverse string
void reverse(string str){

   //base case
    if(str.length()==0){
        return;  
    }

    string ros = str.substr(1);   //rest of string
    reverse(ros);
    cout<<str[0];
}

  int main() {
    string s;
    cout<<"Enter string: ";
    getline(cin,s);

 
   cout<<"Reverse of "<<s<<" is = "; 
 
   //call reverse function
   reverse(s);
   
   cout<<endl;
   
    return 0;
}
