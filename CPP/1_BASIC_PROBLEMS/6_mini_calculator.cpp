               // CREATE A MINI CALCULATOR

// Problem Statement:

// Write a program that accepts two numbers a and b from the user and performs basic arithmetic operations based on the user's choice. The operations include addition, subtraction, multiplication, division, and an option to quit the program. The program should continue prompting for operations until the user chooses to quit.

// Input:
// Two integers a and b.
// A choice c to select an operation from the menu.

// Operations:
// Addition (+)
// Subtraction (-)
// Multiplication (*)
// Division (/)
// Quit the program.

// Output:
// The result of the selected operation or an error message if the operation is invalid or the division is attempted with invalid inputs (e.g., non-positive numbers).

// Example 1:

// Input:  Enter 2 no: 10, 5
// Choose an operation
// 1.+,
// 2.-,
// 3.*,
// 4./ 
// 5.Quit

// INPUT : 1

// Output: Your answer is: 15  (10+5=15)


#include <iostream>
using namespace std;
int main() {
    int a,b,c;
  cout<<"enter 2 no:";
  cin>>a;
  cin>>b;
  do{
  cout<<"\nchoose an operation\n1.+,\n2.-,\n3.*,\n4./ \n5.Quit\n" ;
  cin>>c;
  cout<<"---------------------\n";
  switch(c)
  {
     case 1:
            cout<<"your ans is: "<<a+b<<"\n";
            break;
     case 2:
           cout<<"your ans is: "<< a-b<<"\n";
            break;
     case 3:
          cout<<"your ans is: "<<a*b<<"\n";
          break;
     case 4:
          if(a<=0|| b<=0){
            cout<<"ERROR!!!";
            break;
          }
          cout<<"your ans is: "<<(float)a/b<<"\n";
            break;
     case 5:
           break;
     default:
          cout<<"error\n";
          break;
    }
}while(c!=5);

  return 0;
  }