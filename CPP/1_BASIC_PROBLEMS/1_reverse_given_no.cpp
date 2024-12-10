
#include<iostream>
using namespace std;


int main(){
int n;
cout<<"Enter a no: ";
cin>>n;

//print reverse of given no
while(n>0){
  int r = n % 10;
  cout<<""<<r;
  n /= 10;
}

return 0;
}