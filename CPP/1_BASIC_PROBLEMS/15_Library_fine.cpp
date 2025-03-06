//Problem Statement: Library Fine Calculation
// A library imposes a fine for returning books late. The fine structure is as follows:

// If the book is returned on or before the due date, no fine is charged.
// If the book is returned after the due date but in the same month and year, the fine is ₹15 per day late.
// If the book is returned after the due month but in the same year, the fine is ₹500 per month late.
// If the book is returned in a different year (after the due year), the fine is ₹10,000 (fixed penalty).

// Input Format:
// The program takes six integers as input:

// d1, m1, y1 → Actual return date (day, month, year)
// d2, m2, y2 → Due date (day, month, year)
// Output Format:
// Print the library fine in rupees.

// Example 1: (Returned late in the same month)
// Input:
// Enter return date (d1 m1 y1): 9 6 2024
// Enter due date (d2 m2 y2): 6 6 2024

// Explanation:
// The book was returned 3 days late in June 2024.
// Fine = 3 × ₹15 = ₹45.

// Output:
// Library fine: 45 rupees
// Example 2: (Returned late in a different month)

// Input:
// Enter return date (d1 m1 y1): 5 8 2024
// Enter due date (d2 m2 y2): 5 6 2024

// Explanation:
// The book was returned 2 months late in the same year (2024).
// Fine = 2 × ₹500 = ₹1000.

// Output:
// Library fine: 1000 rupees

// Example 3: (Returned in the next year)

// Input:
// Enter return date (d1 m1 y1): 5 1 2025
// Enter due date (d2 m2 y2): 31 12 2024

// Explanation:
// The book was returned in the next year (2025).
// Fixed fine = ₹10,000.
// Output:
// Library fine: 10000 rupees




#include <iostream>
using namespace std;

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y1 > y2) {
        return 10000; // Year late -> Fixed penalty
    } 
    else if (y1 == y2) {
        if (m1 > m2) {
            return ((m1 - m2) * 500); // Month late -> 500 per month
        } 
        else if (m1 == m2 && d1 > d2) {
            return ((d1 - d2) * 15); // Day late -> 15 per day
        }
    }
    return 0; // No fine if returned on time or earlier
}

int main() {
    int d1, m1, y1, d2, m2, y2;
    cout << "Enter return date (d1 m1 y1): ";
    cin >> d1 >> m1 >> y1;
    cout << "Enter due date (d2 m2 y2): ";
    cin >> d2 >> m2 >> y2;
    
    int fine = libraryFine(d1, m1, y1, d2, m2, y2);
    cout << "Library fine: " << fine << " rupees" << endl;
    
    return 0;
}
