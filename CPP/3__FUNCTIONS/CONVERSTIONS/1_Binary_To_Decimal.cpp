// Problem Statement:
// Write a program to convert a binary number to its decimal equivalent.

// Input:
// A binary number (a number containing only digits 0 and 1).
// Output:
// The decimal equivalent of the given binary number.
// If the input contains any digit other than 0 or 1, display an error message:
// "Wrong input!!! Binary digits only contain 0 and 1"

// Example 1:
// Input: Give a binary no: 1011
// Output:
// Decimal of 1011 is = 11

// Example 2 (Invalid Input):
// Input: Give a binary no: 1201
// Output:
// Wrong input!!!  
// Binary digits only contain 0 and 1

#include<iostream>
using namespace std;


//Function to convert binary no to decimal
int binaryTodecimal(int n){
     int ans =0;
     int x = 1;
     while(n>0){
        int rem = n % 10 ; //last digit
          if(rem > 1 || rem < 0){
            cout<<"\nWrong input!!!\nBinary digits only contain 0 and 1\n";
             //cause binary digits contain only 0 and 1
             return 0;
          }

             ans += x*rem;
             x *= 2;   //update power of 2
             n /= 10;
             
     }

     return ans;
}



int main(){
    int num;
    cout<<"Give a binary no: ";
    cin>>num;

    cout<<"Decimal of "<<num<<" is = "<<binaryTodecimal(num);
    cout<<"\n";
    return 0;
}