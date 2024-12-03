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