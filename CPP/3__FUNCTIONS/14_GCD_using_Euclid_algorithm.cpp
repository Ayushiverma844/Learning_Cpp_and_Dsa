//Euclid Algorithm to find GCD (greatest common factor)

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