//Problem Statement:
// Write a C++ program to check whether a given number n is a power of 2 or not.



#include<iostream>
using namespace std;

bool power_of_2(int n){
    return (n && !(n & n-1));
}
int main(){
  int n;
  cout<<"Enter a no ";
  cin>>n;

  if(power_of_2(n)){
    cout<<"It is power of 2.";
  }else{
    cout<<"It is not power of 2.";
  }
  cout<<endl;
  return 0;

}