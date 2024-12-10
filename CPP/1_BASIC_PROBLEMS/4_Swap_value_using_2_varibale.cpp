//Wap to accept 2 no from the user and swap them. 

#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter a= ";
    cin>>a;
    cout<<"Enter b=";
    cin>>b;
    
    a = a+b;
    b = a-b;
    a = a-b;
    
    cout<<"a="<<a;
    cout<<"\nb="<<b;
    return 0;
}