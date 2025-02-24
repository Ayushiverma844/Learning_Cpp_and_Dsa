// Problem Statement:
// Given a positive integer n, your task is to print the reverse of that number.

// Input: A positive integer n.
// Output: Print the digits of n in reverse order.

// Example:
// Input:  12345
// Output: 54321


#include<iostream>
using namespace std;


int main(){
int n;
cout<<"Enter a no: ";
cin>>n;

//print reverse of given no
while(n>0){
  int r = n % 10;
  cout<<""<<r;
  n /= 10;
}

return 0;
}