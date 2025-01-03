// Tower Of Hanoi

#include <iostream>
using namespace std;

// Function to implement Tower of Hanoi
void towerOfHanoi(int n, char source, char target, char helper) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    // Move n-1 disks from source to helper
    towerOfHanoi(n - 1, source, helper, target);
    // Move the nth disk from source to target
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    // Move the n-1 disks from helper to target
    towerOfHanoi(n - 1, helper, target, source);
}

int main() {
    int n;

    cout << "Enter the number of disks: ";
    cin >> n;

    // Solve Tower of Hanoi
    towerOfHanoi(n, 'A', 'C', 'B'); // A = source, C = target, B = helper

    return 0;
}
