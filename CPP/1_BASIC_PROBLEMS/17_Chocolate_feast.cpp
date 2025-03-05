//Problem Statement: Chocolate Feast

// A person has ₹n and wants to buy chocolates. Each chocolate costs ₹c. Additionally, for every m wrappers collected, the person can exchange them for one additional chocolate.

// Write a program to calculate the total number of chocolates the person can eat, including the chocolates obtained by exchanging wrappers.

// Input Format:
// The program should take three integers as input:

// n – Total money available
// c – Cost of one chocolate
// m – Number of wrappers required for one extra chocolate
// Output Format:
// Print the total number of chocolates the person can eat.

// Example:

// Input:
// 10 2 5
// Explanation:
// ₹10 can buy 10/2 = 5 chocolates initially.
// The 5 chocolates provide 5 wrappers.
// Since 5 wrappers can be exchanged for 1 more chocolate, the total chocolates eaten = 5 + 1 = 6.
// Output:
// Total chocolates eaten: 6



#include <iostream>
using namespace std;

int chocolateFeast(int n, int c, int m) {
    // Initial number of chocolates you can buy
    int choc = n / c;  
    
    // Start with the wrappers you get from the initial chocolates
    int repper = choc;
    
    // Loop to exchange wrappers for more chocolates
    while (repper >= m) {
        // Get new chocolates from wrappers
        int newChocolates = repper / m;
        choc += newChocolates;
        
        // Update the remaining wrappers: 
        // New wrappers from the new chocolates + leftover wrappers
        repper = (repper % m) + newChocolates;
    }
    
    return choc;
}

int main() {
    int n, c, m;
    
    // Example input: n = money available, c = cost of a chocolate, m = wrappers needed for one new chocolate
    cout << "Enter the amount of money, cost of one chocolate, and number of wrappers for a new chocolate: ";
    cin >> n >> c >> m;
    
    // Call the chocolateFeast function and output the result
    int result = chocolateFeast(n, c, m);
    cout << "Total chocolates eaten: " << result << endl;
    
    return 0;
}
