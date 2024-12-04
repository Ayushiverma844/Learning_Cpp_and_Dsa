//     1 
//    1 2 
//   1 2 3 
//  1 2 3 4 
// 1 2 3 4 5

#include<iostream>
using namespace std;

int main(){
    int n= 5;

    //print  
    for(int i=1; i<=n ; i++){
        //SPACES
        for(int j=n-1;j>=i;j--){
           cout<<" ";
        }

        //numbers
        for(int j=1;j<=i;j++){
            cout<<""<<j<<" ";
        }
        cout<<"\n";
    }

    return 0;
}