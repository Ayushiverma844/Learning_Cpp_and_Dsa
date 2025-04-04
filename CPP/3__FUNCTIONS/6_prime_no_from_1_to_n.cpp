//Problem Statement:
// Write a C++ program to find and display all prime numbers between 1 and a given number n.



#include<iostream>
using namespace std;

//function to check prime
bool is_prime(int n){
  if (n < 2)  // 0 and 1 are not prime
  return false;
  if (n == 2) // 2 is the smallest prime
  return true;
  
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

cout<<"Prime no between 1 to "<<n<<" =\n";
for(int i=1;i<=n;i++){
    if(is_prime(i)){
      cout<<""<<i<<"\n";
    }
}


return 0;
}