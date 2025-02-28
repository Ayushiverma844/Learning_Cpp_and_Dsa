// Problem Statement:

// You are given an array c representing clouds, where:

// c[i] = 0 represents a safe cloud.
// c[i] = 1 represents a thundercloud, which cannot be stepped on.
// Starting from the first cloud (c[0]), you need to reach the last cloud (c[n-1]) with the minimum number of jumps.

// You can jump 1 step or 2 steps at a time.
// Write a function that returns the minimum number of jumps required to reach the last cloud.

// Example:
// Input: vector<int> c = {0, 1, 0, 0, 0, 1, 0};
// Explanation:
// Start at index 0.
// Cannot jump to index 1 (thundercloud).
// Jump 2 steps to index 2.
// Jump 1 step to index 3.
// Jump 2 steps to index 5 (but it's a thundercloud, so not possible).
// Instead, jump 1 step to index 4.
// Jump 2 steps to index 6 (last cloud).
// Total Jumps: 4
// Output: 4

#include <iostream>
#include <vector>

using namespace std;

// Function to find minimum jumps
int minJumps(vector<int>& c) {
    int jumps = 0;
    int i = 0;
    int n = c.size();

    while (i < n - 1) {
        if (i + 2 < n && c[i + 2] == 0) {
            // if possible take 2 step
            i += 2;
        } else {
            //otherwise 1 step
            i += 1;
        }
        jumps++;
    }

    return jumps;
}

int main() {
    vector<int> c = {0, 1, 0, 0, 0, 1, 0}; // Example input

    cout <<"Possible minimum jump is = "<< minJumps(c) << endl; // Output: 4

    return 0;
}
