// Problem Statement:
// Write a C++ program to calculate the sum of the first n natural numbers using recursion.
// The program should prompt the user to enter a number n and then use a recursive function to compute the sum 1 + 2 + ... + n. Finally, display the result.


#include<iostream>
using namespace std;


//sum of n terms using recurssion

int sum(int n){ 
   if(n==0){
    return 0;
   }

   int prevSum = sum(n-1);
   return n + prevSum ;
}


int main() {
    int n;

    cout<<"Enter no : ";
    cin>>n;

    int result = sum(n); //call function

    cout<<"Sum from 1 to "<<n<<" = "<<result<<endl;
    
    return 0;
}