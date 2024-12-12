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
