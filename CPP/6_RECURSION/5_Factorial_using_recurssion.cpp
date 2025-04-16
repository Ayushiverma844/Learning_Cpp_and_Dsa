// 🔹 Problem Statement: Calculate Factorial of a Number Using Recursion
// Write a C++ program to calculate the factorial of a given non-negative integer using a recursive function.

//  Requirements:
// Accept an integer input n from the user.

// Use a recursive function fact(int n) to compute the factorial.

// Display the result in the format:
// Factorial of n = result

//  Note:
// Factorial of 0 is 1.

// Factorial of a number n is defined as:
// n! = n × (n - 1) × (n - 2) × ... × 1

//  Sample Input/Output:
// Enter value= 5
// Factorial of 5 = 120


#include<iostream>
using namespace std;

//function to calculate factorial
int fact(int n){
  if(n==0){
    return 1;
  }
  return n * fact(n-1);
}


int main(){
int n;
cout<<"Enter value= ";
cin>>n;

cout<<"Factorial of "<<n<<" = "<<fact(n);

  return 0;      
       
}