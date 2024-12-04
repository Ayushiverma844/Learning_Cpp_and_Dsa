//     * * * * * 
//    * * * * * 
//   * * * * * 
//  * * * * * 
// * * * * * 

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

        //STARS
        for(int j=1;j<=n;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }

    return 0;
}