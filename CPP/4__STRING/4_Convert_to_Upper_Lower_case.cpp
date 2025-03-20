// Problem Statement:
// Write a C++ program that converts a given string to uppercase and then to lowercase without using built-in functions like toupper() or tolower(). The program should:

// Take a predefined string as input.

// Convert all lowercase letters ('a' to 'z') to uppercase ('A' to 'Z') using ASCII value manipulation.

// Convert all uppercase letters ('A' to 'Z') to lowercase ('a' to 'z') using ASCII value manipulation.

// Display the original string, the converted uppercase string, and the converted lowercase string.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str ="abABCDieh" ;
    
    cout<<"Given string= "<<str<<endl;
    //convert to upper case
    //'a' - 'A' = 32

  for(int i=0;i<str.size();i++){
      if(str[i] >='a' && str[i] <= 'z'){
        str[i] -= 32;
      }
    } 

    cout<<"UpperCase =  "<<str<<endl;

    //convert to lower case
 for(int i=0;i<str.size();i++){
      if(str[i] >='A' && str[i] <= 'Z'){
        str[i] += 32;
      }
    } 
    cout<<"LowerCase = "<<str<<endl;

    return 0;
}