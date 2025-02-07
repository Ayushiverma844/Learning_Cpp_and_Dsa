// A junior from MCA at MANIT Bhopal has just learned about their pointers and is excited to explore them. However, they are worried about whether their pointer exists in memory or not!

// Given a sorted array of N distinct integers representing memory addresses and an integer P (the junior’s pointer), determine if P exists in the array using Binary Search.

// If P is found, print "Pointer found at index X" (1-based index). Otherwise, print "Pointer does not exist".

// Output Format

// If P exists in the array, print:
// "Pointer found at index X" (1-based index of P).
// Otherwise, print:
// "Pointer does not exist".
// **Example **

// Input 1:
// 5
// 1 3 5 7 9
// 5
// Output 1:
// Pointer found at index 3

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Input: size of array
    int n;
    cin >> n;

    // Array declaration
    vector<int> arr(n);

    // Input: elements in sorted array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input: pointer value to search
    int p;
    cin >> p;

    // Binary search
    int st = 0, end = n - 1;
    
    while (st <= end) {
        int mid = (st + end) / 2;

        if (arr[mid] == p) {
            cout << "Pointer found at index " << mid + 1 << endl;
            return 0;
        } else if (arr[mid] < p) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // If not found
    cout << "Pointer does not exist" << endl;
    return 0;
}
