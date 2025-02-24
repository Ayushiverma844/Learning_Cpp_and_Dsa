// Problem Statement:

// Given a positive integer n, determine if the number is an Armstrong number.

// An Armstrong number is a number where the sum of the cubes of its digits is equal to the number itself. For example, 153 is an Armstrong number because 
// 153 = 1^3 + 5^3 + 3^3 == 153
//Output: 153 is an armstrong no

#include<iostream>
using namespace std;


int main(){
int n,sum=0;
cout<<"Enter a no: ";
cin>>n;

int num = n;  //store orignal no itno num

// calculate sum of cube of each digit 
// armstrong no = example = 153 =  (1^3 + 5^3 + 3^3 equals 153.) 
while(n>0){
  int r = n % 10;
  sum = sum + (r*r*r);
  n /= 10;
}
if(sum == num){
  cout<<""<<num<<" is an armstrong no\n";
}else{
   cout<<""<<num<<" is not an armstrong no\n";
}

return 0;
}