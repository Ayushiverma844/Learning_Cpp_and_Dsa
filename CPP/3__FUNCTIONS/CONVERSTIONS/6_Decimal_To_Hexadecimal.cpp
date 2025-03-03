//Problem Statement:

// Write a program that converts a given decimal number to its hexadecimal equivalent.

// Input:
// A positive integer n (0 ≤ n ≤ 10^6).
// Output:
// The hexadecimal representation of the given decimal number n.

// Functionality:
// The program should read a decimal number from the user.
// It should then convert the decimal number to its hexadecimal representation.
// Finally, it should display the hexadecimal equivalent of the input decimal number.

// For example:
// Input: 255
// Output: FF

// Input: 16
// Output: 10

// Input: 0
// Output: 0


#include<iostream>
using namespace std;

// Function to convert decimal to hexadecimal
string DecimalToHexadecimal(int n) {
    if (n == 0) return "0";  // Special case for 0

    string hex = "";
    char hexChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    // Keep dividing the number by 16 and collect the remainders
    while (n > 0) {
        int remainder = n % 16;
        hex = hexChars[remainder] + hex;  // Prepend the corresponding hex character
        n /= 16;
    }

    return hex;
}

int main() {
    int num;
    cout << "Give a decimal number: ";
    cin >> num;

    cout << "Hexadecimal of " << num << " is = " << DecimalToHexadecimal(num);
    cout << "\n";
    return 0;
}