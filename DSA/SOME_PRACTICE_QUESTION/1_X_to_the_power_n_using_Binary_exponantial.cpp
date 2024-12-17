//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Example 1:
// Input: x = 2.00000, n = 10
// Output: 1024.00000

// Binary exponentiation

#include <iostream>
#include <cmath>  // For handling edge cases like NaN or infinity
using namespace std;

double pow_x(double x, int n) {
    // Edge case when n is 0
    if (n == 0) return 1.0;
    
    // Edge case when x is 0 and n is negative, which would be undefined
    if (x == 0 && n < 0) {
        cout<<"Invalid!!!";
    }

    // If n is negative, we invert x and work with the positive exponent
    long long binForm = n;  // Use long long for safe range of n values
    
    if (n < 0) {
        x = 1 / x;  // Invert x for negative exponent
        binForm = -binForm;  // Work with positive exponent now
    }

    double result = 1.0;

    // Binary exponentiation approach
    while (binForm > 0) {
        if (binForm % 2 == 1) {
            result *= x;
        }
        x *= x;  // Square the base for the next higher power of 2
        binForm /= 2;  // Divide the exponent by 2
    }

    return result;
}

int main() {
    double x = 2.00000;
    int n = 10;
    cout << "Result: " << pow_x(x, n) << endl;  // Should output 1024.00000
    return 0;
}

