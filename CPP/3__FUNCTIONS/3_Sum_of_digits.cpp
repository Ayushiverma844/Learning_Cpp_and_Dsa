// Problem Statement:
// Write a C++ program to calculate the Sum of Digits of a given number.

// Explanation:
// The user inputs an integer  𝑛
// The program extracts each digit of  𝑛
// adds them together, and returns the sum.
// Example:
// Input: 143
// Calculation: 
// 1+4+3=8
// Output: Sum of Digits of 143 = 8

// Constraints:
// n should be a positive integer.
// If n=0, the sum should be 0.

#include<iostream>
using namespace std;

//function to calculate sum of digits
// 143 = 1+4+3 == 8

int SOD(int n){
  int sum = 0;
  while(n>0){
    int r = n%10;
    sum += r;
    n /=10;
  }
  return sum;
}


int main(){
int n;
cout<<"Enter value = ";
cin>>n;

cout<<"Sum of Digits of "<<n<<" = "<<SOD(n);

  return 0;      
       
}