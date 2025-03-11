//Problem Statement:

// Write a C++ program to count the number of 1s in the binary representation of a given integer using bitwise operations.

#include<iostream>
using namespace std;

int no_of_ones(int n){
    int count = 0;
    while (n)
    {
        n = n & (n-1);
        count++;
    }
  return count;  
}

int main(){
  int n;
  cout<<"Enter a no ";
  cin>>n;

  cout<<"no of ones in binary form of "<<n<<" is "<<no_of_ones(n);
  return 0;

}