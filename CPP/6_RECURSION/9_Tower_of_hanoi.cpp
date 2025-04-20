// Problem Statement: Tower of Hanoi
// Write a program to solve the classic Tower of Hanoi puzzle using recursion.

// Description:
// You are given n disks and three rods labeled A (source), B (helper), and C (target). Initially, all disks are stacked on rod A in decreasing order of size (largest at the bottom, smallest at the top). The goal is to move the entire stack to rod C, obeying the following rules:

// Only one disk may be moved at a time.

// Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or an empty rod.

// No larger disk may be placed on top of a smaller disk.

// Input:
// An integer n representing the number of disks.

// Output:
// A step-by-step series of instructions showing how to move the disks from rod A to rod C.

// Example:
// Enter the number of disks: 3
// Move disk 1 from A to C
// Move disk 2 from A to B
// Move disk 1 from C to B
// Move disk 3 from A to C
// Move disk 1 from B to A
// Move disk 2 from B to C
// Move disk 1 from A to C



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
