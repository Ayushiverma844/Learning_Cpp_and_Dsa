// Problem: Bon Appetit - Bill Splitting
// Anna and her friend are out at a restaurant, and they have ordered some food. The waiter provides them with a bill containing multiple items. However, Anna didn't eat one of the items on the bill, and her friend paid for her share of the meal. Anna has a question: was she charged the correct amount?

// To help Anna determine if she was overcharged, you are given the following:

// A list of integers, bill[], representing the cost of each item on the bill.
// An integer k, which is the index of the item that Anna did not eat.
// An integer b, which is the amount Anna was charged by her friend.
// You need to determine if Anna was charged correctly for her share of the meal, and if not, how much extra she paid.

// Input:
// bill[]: A vector of integers where bill[i] represents the price of the i-th item on the bill.
// k: An integer representing the index of the item that Anna did not eat (0-based index).
// b: An integer representing the amount Anna was charged by her friend.

// Output:
// If Anna was charged the correct amount, output "Bon Appetit".
// If Anna was overcharged, output the amount of extra money she paid (i.e., b - totalAmount), where totalAmount is the fair share of the bill excluding the item Anna did not eat.

// Example:
// Input 1:
// bill = [3, 10, 2, 9]
// k = 1
// b = 12

// Output 1:  5

// Explanation:
// Anna did not eat the item at index k = 1 (the item worth 10).
// The total cost of the items Anna ate is 3 + 2 + 9 = 14.
// Anna’s share should be half of this amount, which is 14 / 2 = 7.
// Anna was charged b = 12. The extra amount she was charged is 12 - 7 = 5.
// The output is 5.

// Input 2:
// bill = [3, 10, 2, 9]
// k = 1
// b = 7
// Output 2: Bon Appetit

#include <iostream>
#include <vector>
using namespace std;

void bonAppetit(vector<int> bill, int k, int b) {
    int totalAmount = 0;
    
    // Sum up the items in the bill except for the item Anna didn't eat
    for(int i = 0; i < bill.size(); i++) {
        if(i != k) {
            totalAmount += bill[i];
        }
    }
    
    // The total amount is divided into two parts
    totalAmount /= 2;
    
    // Now check if Anna was overcharged
    if(b > totalAmount) {
        cout << b - totalAmount << endl; // Extra amount Anna was charged
    } else {
        cout << "Bon Appetit" << endl; // Anna was charged the correct amount
    }
}

int main() {
    // Example test case
    vector<int> bill = {3, 10, 2, 9}; // Bill amounts
    int k = 1;  // The index of the item Anna didn't eat
    int b = 12; // The amount Anna was charged
    
    bonAppetit(bill, k, b);  // Call the function with the test case

    return 0;
}
