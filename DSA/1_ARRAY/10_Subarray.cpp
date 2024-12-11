#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter size of array : ";
    cin>>n;

    int a[n];

    //store elements in array
    cout<<"Enter\n";
     for(int i=0;i<n;i++){
        cin>>a[i];
     }

//The total number of subarrays in an array of size N is N * (N + 1) / 2.
     for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<a[k]<<" ";
            }
            cout<<"\n";
        }
     }

     return 0;
}