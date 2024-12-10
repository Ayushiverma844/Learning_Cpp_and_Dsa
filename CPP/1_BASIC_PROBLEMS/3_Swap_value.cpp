//Wap to accept 2 no from the user and swap them. 

#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter a= ";
    cin>>a;
    cout<<"Enter b=";
    cin>>b;
    c=a;
    a=b;
    b=c;
    cout<<"a="<<a;
    cout<<"\nb="<<b;
    return 0;
}