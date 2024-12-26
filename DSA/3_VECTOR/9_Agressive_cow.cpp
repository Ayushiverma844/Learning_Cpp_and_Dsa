
// AGGRCOW - Aggressive cows
// #binary-search

// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).
// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi

// Output
// For each test case output one integer: the largest minimum distance.

// Example

// Input:
// 1
// 5 3  (no of stall,no of cows)
// {1,2,8,4,9}

// Output:
// 3

// Output details:
// FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
// resulting in a minimum distance of 3.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& arr, int n, int C, int dist) {
    int lastPosition = arr[0];
    int count = 1; // First cow placed

    for (int i = 1; i < n; ++i) {
        if (arr[i] - lastPosition >= dist) {
            count++;
            lastPosition = arr[i];
            if (count == C) return true;
        }
    }
    return false;
}

int getDistance(vector<int>& arr, int n, int C) {
    sort(arr.begin(), arr.end());

    int st = 1; // Start with the minimum possible distance (1)
    int end = arr[n-1] - arr[0]; // Maximum possible distance
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, C, mid)) {
            //right
            ans = mid; // If it's possible, try for a larger distance
            st = mid + 1;
        } else {
            //left
            end = mid - 1; // Try for a smaller distance
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 8, 4, 9};
    int n = arr.size();    //no of stall
    int C = 3; // Number of cows to place

    cout << "Maximum minimum distance: " << getDistance(arr, n, C) << endl;
    return 0;
}