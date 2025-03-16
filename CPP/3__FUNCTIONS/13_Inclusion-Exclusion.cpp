                                          //Inclusion - Exclusion Principle

//

#include<iostream>
using namespace std;

int Divisible(int n, int a, int b) {
    int c1 = n / a;  // Numbers divisible by a
    int c2 = n / b;  // Numbers divisible by b
    int c3 = n / (a * b);  // Numbers divisible by both a and b

    // Apply inclusion-exclusion principle
    return (c1 + c2 - c3);
}

int main() {
    int n, a, b;

    cout << "Enter a number n: ";
    cin >> n;

    cout << "Enter two numbers a and b to find divisibles: ";
    cin >> a >> b;

    if (a == 0 || b == 0) {
        cout << "Error!!! a or b cannot be zero." << endl;
        return 0;
    }

    // Call Divisible function and display result
    int result = Divisible(n, a, b);
    cout << "Count of numbers divisible by " << a << " or " << b << " from 1 to " << n << " is: " << result << endl;

    return 0;
}
