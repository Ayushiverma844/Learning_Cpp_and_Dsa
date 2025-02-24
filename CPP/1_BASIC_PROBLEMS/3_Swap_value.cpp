// Problem Statement:

// Write a program that accepts two integers a and b from the user, swaps their values, and then prints the swapped values.
// Input:
// Enter a= 5
// Enter b= 10

// Output:
// a=10
// b=5

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