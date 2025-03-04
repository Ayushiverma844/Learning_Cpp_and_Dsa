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
