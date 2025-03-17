//Euclid Algorithm to find GCD (greatest common factor)

// Problem Statement:

// Write a C++ program that takes two positive integers, a and b, as input and calculates the Greatest Common Divisor (GCD) and Least Common Multiple (LCM) of the two numbers using the Euclidean algorithm for GCD.

// The program should:

// Accept two integers as input.
// Ensure that neither of the integers is zero; if either number is zero, display an error message and terminate.
// Calculate the GCD of the two integers using the Euclidean algorithm.
// Calculate the LCM of the two integers using the formula:
// LCM (𝑎,𝑏) = 𝑎× 𝑏 / GCD(𝑎,𝑏)

 
// Output both the GCD and LCM of the two integers.

// Constraints:
// Both a and b must be positive integers.


#include<iostream>
using namespace std;

int GCD(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int main() {
    int a, b;
    
    cout << "Enter two numbers a and b : ";
    cin >> a >> b;

    // Ensure neither number is zero
    if (a == 0 || b == 0) {
        cout << "Error!!! a or b cannot be zero." << endl;
        return 0;
    }

    // Calculate the product of a and b after input
    int m = a * b;

    // Call GCD function and display result
    int result = GCD(a, b);
    cout << "GCD of " << a << " and " << b << " = " << result << endl;
    cout << "LCM of " << a << " and " << b << " = " << m / result << endl;  // hcf * lcm = a * b

    return 0;
}