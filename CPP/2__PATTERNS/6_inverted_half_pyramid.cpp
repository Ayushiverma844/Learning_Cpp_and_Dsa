// *****
// ****
// ***
// **
// *


#include<iostream>
using namespace std;

int main(){
    int row = 5;
    int coloumn = 4;

    //print  inverted half pyramid
    for(int i=0; i<row ; i++){
        for(int j=0 ; j<=coloumn-i; j++){

             cout<<"*";

            }
        cout<<"\n";
    }

    return 0;
}