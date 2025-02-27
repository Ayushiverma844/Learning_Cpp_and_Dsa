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
