// Problem Statement:

// You are given an array of integers where each integer represents a type of toy. You are also given an integer k which denotes the maximum number of distinct toy types you are allowed to pick at a time.

// Your task is to find the maximum number of toys you can pick from the array such that you do not pick more than k distinct toy types.

// Input:

// A vector of integers toys representing the sequence of toys.

// An integer k representing the maximum number of distinct toy types allowed.

// Output:

// Return the maximum number of toys that can be picked without exceeding the k distinct types constraint.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxToysPick(const vector<int>& toys, int k) {
    unordered_map<int, int> toyCount; // To count occurrences of each toy type
    int i = 0, maxToys = 0;

    // Iterate over the array with the 'right' pointer
    for (int j = 0; j < toys.size(); ++j) {
        // Add the current toy to the map (increment the count)
        toyCount[toys[j]]++;

        // If the number of distinct toy types exceeds 'k', shrink the window from the left
        while (toyCount.size() > k) {
            toyCount[toys[i]]--;
            if (toyCount[toys[i]] == 0) {
                toyCount.erase(toys[i]);
            }
            i++; // Move the left pointer to shrink the window
        }

        // Update the result with the current window size
        maxToys = max(maxToys, j - i + 1);
    }

    return maxToys;
}

int main() {
    vector<int> toys = {1, 2, 1, 2, 3, 1, 2, 1};  // Toy types
    int k = 2; // Maximum number of distinct toy types allowed

    int result = maxToysPick(toys, k);
    cout << "The maximum number of toys that can be picked is: " << result << endl;

    return 0;
}