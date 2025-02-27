//Write a C++ program to calculate the factorial of a given number n, where n is an input provided by the user.

#include<iostream>
using namespace std;

//function to calculate factorial
int fact(int n){
  int f =1;
  for(int i=1;i<=n;i++){
    f*=i;
  }
  return f;
}


int main(){
int n;
cout<<"Enter value= ";
cin>>n;

cout<<"Factorial of "<<n<<" = "<<fact(n);

  return 0;      
       
}