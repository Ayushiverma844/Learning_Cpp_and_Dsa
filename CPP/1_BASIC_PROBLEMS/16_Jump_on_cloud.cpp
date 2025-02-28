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