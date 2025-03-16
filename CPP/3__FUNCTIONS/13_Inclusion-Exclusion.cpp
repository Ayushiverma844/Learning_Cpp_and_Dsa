                                          //Inclusion - Exclusion Principle

//Problem Statement:
// You are tasked with finding the number of integers between 1 and a given number n that are divisible by either of two specified numbers a or b. You need to apply the Inclusion-Exclusion Principle to count the numbers divisible by a or b while avoiding double-counting those divisible by both.

// The Inclusion-Exclusion Principle states that:

// The count of numbers divisible by either a or b is the sum of the count of numbers divisible by a and the count of numbers divisible by b, minus the count of numbers divisible by both a and b.
// Input:
// A positive integer n representing the upper limit of the range (1 to n).
// Two integers a and b, where a and b are the divisors for which the count of divisible numbers needs to be calculated.
// Output:
// The total count of numbers from 1 to n that are divisible by either a or b.
// Constraints:
// a and b must be positive integers. If either of them is zero, the program should print an error message indicating that a or b cannot be zero.
// Example:
// Input:

// less
// Copy
// Enter a number n: 10
// Enter two numbers a and b to find divisibles: 2 3
// Output:

// vbnet
// Copy
// Count of numbers divisible by 2 or 3 from 1 to 10 is: 7
// In this example, the numbers divisible by 2 are {2, 4, 6, 8, 10}, the numbers divisible by 3 are {3, 6, 9}, and the number divisible by both 2 and 3 is {6}. Thus, using inclusion-exclusion, the count is 5 (from 2) + 3 (from 3) - 1 (from both) = 7.





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
