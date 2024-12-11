#include<iostream>
using namespace std;

int main(){
    int n1,n2,n3;
    cout << "Enter size: ";
    cin >> n1>>n2>>n3;
    int a[n1][n2];   
    int b[n2][n3];

    // Store elements in 1st matrix
    cout << "Enter values of 1st matrix: ";
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            cin >> a[i][j];
        }
    }

   // Store elements in 2nd matrix 
    cout << "Enter values of 2nd matrix: ";
    for(int i = 0; i < n2; i++) {
        for(int j = 0; j < n3; j++) {
            cin >> b[i][j];
        }
    }
   
   // answer array  ==> n1*n2 and n2*n3 ==> n1*n3
    int ans[n1][n3];   
      for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n3; j++) {
            ans[i][j] = 0;
        }
     }

     //PRODUCT
      for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n3; j++) {
            for(int k=0;k<n2;k++){
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
      }

    //print  
    cout<<"Product of two matrix :\n";
      for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n3; j++) {
             cout<<"  "<<ans[i][j];
        }
        cout<<"\n";
     }
    return 0; 
}