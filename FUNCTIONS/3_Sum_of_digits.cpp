#include<iostream>
using namespace std;

//function to calculate sum of digits
// 143 = 1+4+3 == 8

int SOD(int n){
  int sum = 0;
  while(n>0){
    int r = n%10;
    sum += r;
    n = n/10;
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