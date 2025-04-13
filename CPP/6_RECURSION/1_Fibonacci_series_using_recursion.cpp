// Problem Statement:
// Write a C++ program to print the Fibonacci series up to n terms using a recursive function.
//  The program should take the number of terms n as input from the user and display the corresponding Fibonacci sequence.

#include <iostream>
using namespace std;

// Recursive function to return the Fibonacci number at position n
int fibonacci(int n) {
    // Base cases
    if (n <= 1)
        return n;
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}