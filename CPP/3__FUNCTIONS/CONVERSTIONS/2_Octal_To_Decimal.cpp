//Problem Statement:

// Write a C++ program to convert an octal number (base-8) to its decimal equivalent (base-10).
//  The program should take an octal number as input and output its decimal representation. 
// If the input contains any invalid octal digits (i.e., digits other than 0-7),
//  then the program should display an error message and terminate.

#include<iostream>
using namespace std;


//Function to convert octal no to decimal
int octalTodecimal(int n){
     int ans =0;
     int x = 1;
     while(n>0){
        int rem = n % 10 ; //last digit
          if(rem > 7 || rem < 0){
            cout<<"\nWrong input!!!\nOctal digits  contain digits between 0 - 7\n";
             //cause Octal digits  contain digits between 0 - 7
             return 0;
          }

             ans += x*rem;
             x *= 8;   //update power of 8
             n /= 10;
             
     }

     return ans;
}



int main(){
    int num;
    cout<<"Give a octal no: ";
    cin>>num;

    cout<<"Decimal of "<<num<<" is = "<<octalTodecimal(num);
    cout<<"\n";
    return 0;
}