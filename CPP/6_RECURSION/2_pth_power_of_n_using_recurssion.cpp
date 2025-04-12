🔢 Problem: Compute Power Using Recursion
Difficulty: Easy
Topic: Recursion, Math

🧾 Problem Statement:
Write a function that takes two integers n and p and returns the value of n raised to the power p (i.e., 
𝑛
𝑝
n 
p
 ) using recursion.

You must not use any built-in power functions.

🖥️ Function Signature:
cpp
Copy
Edit
int power(int n, int p);
🚦Input:
An integer n representing the base.

An integer p representing the exponent (non-negative).

🧾 Output:
Return a single integer representing the result of 
𝑛
𝑝
n 
p
 .

📥 Sample Input 1:
ini
Copy
Edit
n = 2  
p = 3
📤 Sample Output 1:
Copy
Edit
8


//Pth power of n using recurssion

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
