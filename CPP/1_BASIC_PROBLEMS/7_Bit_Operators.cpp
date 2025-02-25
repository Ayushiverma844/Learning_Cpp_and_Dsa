// Problem Statement:

// Given two integers a and b, perform the following bitwise operations:

// Compute the bitwise AND of a and b.
// Compute the bitwise OR of a and b.
// Compute the bitwise XOR of a and b.
// Perform a left shift on both a and b by 2 positions.
// Perform a right shift on both a and b by 2 positions.
// Find the 1's complement of a and b.
// Input:

// Two integers a and b.
// Output:

// Display the results of each bitwise operation.


#include<iostream>
using namespace std;

int main(){
    int a, b;
    cout << "Enter value of a and b = ";
    cin >> a >> b;

    // Bitwise AND '&'
    cout << "Bitwise AND of a and b = " << (a & b) << endl;

    // Bitwise OR '|'
    cout << "Bitwise OR of a and b = " << (a | b) << endl;

    // Bitwise XOR '^'
    cout << "Bitwise XOR of a and b = " << (a ^ b) << endl;

    // Bitwise left shift '<<'
    //(a << 2) shift 2 places left
    //left shift multiplies the original number by 2^n , where n is no of bits to shift

    cout << "Bitwise Left Shift of a = " << (a << 2) << endl;
    cout << "Bitwise Left Shift of b = " << (b << 2) << endl;

    // Bitwise right shift '>>'
    //(a >> 2) shift 2 places right
    //right shift Divides the original number by 2^n , where n is no of bits to shift

    cout << "Bitwise Right Shift of a = " << (a >> 2) << endl;
    cout << "Bitwise Right Shift of b = " << (b >> 2) << endl;

    //1's compelement  '~'

    cout<<"1's compelement of a = "<<~a<<endl;
    cout<<"1's compelement of b = "<<~b<<endl;


    return 0;
}
