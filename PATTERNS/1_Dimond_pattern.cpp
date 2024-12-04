//    *
//   * *
//  *   *
// *     *
//  *   *
//   * *
//    *

#include<iostream>
using namespace std;


int main(){
int n=4;

//top triangle

for(int i=0;i<n;i++){
  //space
  for(int j=0;j<n-i-1;j++){
    cout<<" ";
  }
  cout<<"*";

  if(i!=0){
    //inner space
    for(int j=0;j<2*i-1;j++){
      cout<<" ";
    }
    cout<<"*";
  }

  //new line
  cout<<"\n";
}

//bottom triangle
for(int i=0;i<n-1;i++){
  //space
  for(int j=0;j<i+1;j++){
    cout<<" ";
  }
  cout<<"*";

  if(i!=n-2){
    //inner space
    for(int j=0;j<2*(n-i)-5;j++){
      cout<<" ";
    }
    cout<<"*";
  }

  //new line
  cout<<"\n";
}

  return 0;      
       
}