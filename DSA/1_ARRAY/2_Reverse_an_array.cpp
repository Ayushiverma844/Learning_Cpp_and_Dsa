#include<iostream>
using namespace std;

int main(){
    
        int size = 10;
        int array[size];
       
       //store in array
       cout<<"\nEnter 10 integers:\n";
        for(int i=0;i<=size-1;i++){
             cin>>array[i];
        }
    
      //print
      cout<<"You entered:\n";
      for(int i=0;i<=size-1;i++){
             cout<<""<<array[i]<<" ";
        }
     //print reverse
     cout<<"\nRverse:\n";
      for(int i=size-1;i>=0;i--){
             cout<<""<<array[i]<<" ";
        }
     
     cout<<"\n";

    return 0;

}