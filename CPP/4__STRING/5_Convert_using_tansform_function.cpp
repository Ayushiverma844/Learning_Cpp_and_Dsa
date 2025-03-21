//Problem Statement:
// Write a C++ program that converts a given string to uppercase and then to lowercase using the transform function from the <algorithm> library. The program should:

// Define a string with both uppercase and lowercase characters.

// Display the original string.

// Convert the entire string to uppercase and print the result.

// Convert the uppercase string back to lowercase and print the result.





#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main() {
    string str ="abABCDieh" ;
    
    cout<<"Given string= "<<str<<endl;
   //transform function
  //transform(first() , last(), where to start(),::toupper/tolower)

    //convert to upper case
   transform(str.begin(),str.end(),str.begin() , :: toupper);
    cout<<"UpperCase = "<<str<<endl;

    //convert to lower case
   transform(str.begin(),str.end(),str.begin() , :: tolower);
    cout<<"LowerCase = "<<str<<endl;

    return 0;
}