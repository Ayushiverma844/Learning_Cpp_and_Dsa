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