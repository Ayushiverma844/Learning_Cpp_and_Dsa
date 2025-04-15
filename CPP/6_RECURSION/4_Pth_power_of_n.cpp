

                                  //Pth power of n using recurssion

//  Problem Statement:

// Write a C++ program to calculate the p-th power of a number n (i.e., n^p) using a recursive function. The program should prompt the user to enter a base number n and an exponent p, and then output the result of raising n to the power of p. The recursive function should use the relation:

// n^p = n× n^(p−1)
 
// with the base case being:

// 𝑛^0 = 1
             


#include<iostream>
using namespace std;

// Function to calculate power using recursion
int power(int n, int p) {
    // Base case: when power is 0, return 1 (n^0 = 1)
    if (p == 0) {
        return 1;
    }

    // Recursive case: n^p = n * n^(p-1)
    return n * power(n, p - 1);
}

int main() {
    int n, p;

    cout << "Enter number: ";
    cin >> n;
 
    cout << "Enter power: ";
    cin >> p; 

    int result = power(n, p); // Call function to compute power

    cout<<"  "<<n<<" ^ "<<p<<" = "<<result<<endl;
    
    return 0;
}
