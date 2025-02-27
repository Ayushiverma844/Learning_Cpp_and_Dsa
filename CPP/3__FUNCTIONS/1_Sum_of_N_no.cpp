//Write a C++ program to calculate the sum of all integers from 1 to n, where n is an input provided by the user.

#include<iostream>
using namespace std;

//function to calculate sum
int Sum(int n){
  int sum =0;
  for(int i=1;i<=n;i++){
    sum+=i;
  }
  return sum;
}


int main(){
int n;
cout<<"Enter value= ";
cin>>n;

cout<<"Sum from 1 to n = "<<Sum(n);

  return 0;      
       
}