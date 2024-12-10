// ****
// *  *
// *  *
// *  *
// ****

#include<iostream>
using namespace std;

int main(){
    int row = 5;
    int coloumn = 4;

    //print  
    for(int i=0; i<row ; i++){
        for(int j=0 ; j<coloumn; j++){

            if(i==0 || i==row-1 || j==0 || j==coloumn-1)
                      cout<<"*";
         
            else
              cout<<" ";
            }
        cout<<"\n";
    }

    return 0;
}