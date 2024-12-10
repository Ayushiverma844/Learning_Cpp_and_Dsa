//Read nd print a 2-D Array.
#include<iostream>
using namespace std;

int main()
{
    int r,c;
 cout<<"Enter no or row & colomn: ";
    cin>>r>>c;
    int arr[r][c];
    for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
             cout<<("enter no ");
               cin>>arr[i][j];
           }
       }
    for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
             cout<<"\n"<<arr[i][j];
           }
       }
   return 0;
}