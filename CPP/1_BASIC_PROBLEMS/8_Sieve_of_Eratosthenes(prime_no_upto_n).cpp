//Find prime number from 2 to n using SIEVE EROTOSTHENES METHOD

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