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