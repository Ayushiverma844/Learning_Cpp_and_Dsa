//Problem Statement:
// Write a C++ program to check whether a given number n is a prime number or not.

// The program should:

// Take an integer n as input from the user.
// Check if n is prime using a function is_prime(int n), which:
// Iterates from 2 to n-1 and checks if n is divisible by any number.
// Returns true (1) if n is prime, otherwise false (0).
// Print whether the number is prime or not prime based on the function's output.

#include<iostream>
using namespace std;

//function to check prime
bool is_prime(int n){
  for(int i=2;i<n;i++){
    if(n%i==0)
      return 0; //false(not prime)
  }
   return 1;   //true(prime)
} 

int main(){
int n;
cout<<"Enter a no: ";
cin>>n;

if(is_prime(n)){
  cout<<""<<n<<" is prime\n";
}else{
  cout<<""<<n<<" is not prime\n";
}

return 0;
}