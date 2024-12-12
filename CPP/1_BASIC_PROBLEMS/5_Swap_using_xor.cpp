//Swap value without using addition and use only 2 variables

#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter value of a and b = ";
    cin>>a>>b;

   //swap using xor 
    // 1 ^ 1 = 0
    // 0 ^ 0 = 0
    // 1 ^ 0 = 1
    // 0 ^ 1 = 1

    a = a ^ b;  // Step 1
    b = a ^ b;  // Step 2
    a = a ^ b;  // Step 3

    cout<<"value of a = "<<a<<endl;
    cout<<"value of b = "<<b<<endl;

   return 0;
}