#include<iostream>
using namespace std;


int main(){
int n=4;

//Outer loop
 for(int i=0;i<4;i++){

  //spaces
  for(int j=0;j<n-i-1;j++){
      cout<<" ";
  }

  //num 1
  for(int j=1;j<=i+1;j++){
    cout<<j;
  }
  //num 2
    for(int j=i;j>=1;j--){
    cout<<j;
  }

  //new line
  cout<<"\n";

 }
  
  return 0;      
       
}