#include<iostream>
#include<cmath>   // For the pow() function (used for reversing the result later)
using namespace std;

// Function to add two binary numbers
int Add2Binary(int a, int b) {
    int result = 0;  // To store the result
    int carry = 0;   // To store the carry
    int power = 1;   // To shift the result to the correct place value
    
    // Loop until both a and b are 0 and there is no carry left
    while (a > 0 || b > 0 || carry) {
        // Get the last bit of both numbers and the carry
        int bitA = a % 10;  // Last bit of a
        int bitB = b % 10;  // Last bit of b
        
        // Sum the bits and the carry
        int sum = bitA + bitB + carry;
        
        // The result's current bit is the sum modulo 2 (0 or 1)
        result += (sum % 2) * power;
        
        // Carry for the next bit (1 if sum is 2 or 3, else 0)
        carry = sum / 2;
        
        // Move to the next bit (shift a, b, and the power)
        a /= 10;
        b /= 10;
        power *= 10;  // Shift the result to the next place value
    }
    
    return result;
}

int main() {
    int a, b;
    cout << "Give 2 binary numbers: ";
    cin >> a >> b;

    cout << " " << a << "\n+" << b << "\n________\n" << Add2Binary(a, b);
    cout << "\n";
    return 0;
}
