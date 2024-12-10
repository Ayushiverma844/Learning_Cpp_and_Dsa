// *      *
// **    **
// ***  ***
// ********
// ********
// ***  ***
// **    **
// *      *


#include<iostream>
using namespace std;

int main(){
    int n= 4;
    int count=1;
  

    //print  
      
      //upper
    for(int i=1; i<=n ; i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        //spaces
        int space = 2*n - 2*i;
         for(int j=1;j<=space;j++)
           cout<<" ";
        
         for(int j=1;j<=i;j++){
            cout<<"*";
        }

        cout<<"\n";
    }

     //lower
        //upper
    for(int i=n; i>=1 ; i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        //spaces
        int space = 2*n - 2*i;
         for(int j=1;j<=space;j++)
           cout<<" ";
        
         for(int j=1;j<=i;j++){
            cout<<"*";
        }

        cout<<"\n";
    }

    return 0;
}