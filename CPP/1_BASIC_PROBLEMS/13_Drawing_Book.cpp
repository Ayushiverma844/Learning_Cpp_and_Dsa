// Given a book with n pages, determine the minimum number of page turns required to reach page p. The book can be flipped from either the front or the back.
// Input:  An integer n (total pages in the book).
//         An integer p (target page number).
// Output: The minimum number of page turns required to reach page p.

// Example:
// Input: n = 6, p = 5
// Output: 1

#include <iostream>
#include <algorithm> // For using the min() function
using namespace std;

// Function to calculate the minimum number of pages to turn
int pageCount(int n, int p) {
    int count_front = (p / 2);  // Number of pages turned from the front
    int count_back = (n / 2) - (p / 2);  // Number of pages turned from the back
    
    // Returning the minimum number of turns required
    return min(count_front, count_back);
}

int main() {
    int n, p;
    
    // Taking input for total number of pages and target page
    cout << "Enter total number of pages (n): ";
    cin >> n;
    cout << "Enter target page (p): ";
    cin >> p;

    // Calling the function and displaying the result
    int result = pageCount(n, p);
    cout << "Minimum number of page turns: " << result << endl;

    return 0;
}
