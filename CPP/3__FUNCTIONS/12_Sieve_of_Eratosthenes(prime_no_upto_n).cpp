// Problem Statement:
// Write a program to find all prime numbers from 2 to N using the Sieve of Eratosthenes method.

// Input:
// An integer N (2 ≤ N ≤ 10^6), representing the upper limit of the range.
// Output:
// A list of all prime numbers between 2 and N, printed in ascending order.
// Constraints:
// The solution should run efficiently for large values of N (up to 10^6).
// Use an array-based sieve approach to mark non-prime numbers.

#include<iostream>
using namespace std;

void prime_Sieve(int n) {
    int prime[n + 1] = {0};  // Array to mark prime numbers (0 means prime, 1 means not prime)

    // Mark non-primes
    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == 0) {  // If i is prime
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 1;  // Mark multiples of i as non-prime
            }
        }
    }

    // Print all prime numbers
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) {  // If i is prime
            cout << i << " ";
        }
    }
    cout << endl;
}


int main() {
    int n;
    cout << "Enter a number : ";
    cin >> n;

    prime_Sieve(n); // Call the sieve function to print primes up to n

    return 0;
}