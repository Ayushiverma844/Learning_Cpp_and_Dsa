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