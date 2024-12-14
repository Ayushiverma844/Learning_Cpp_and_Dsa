// Question: 0/1 Knapsack Problem
// You are given a list of items, where each item has a weight and a value. You are also given a 
//knapsack with a limited capacity. The objective is to determine the maximum total value of items 
//that can be placed in the knapsack, subject to the constraint that the total weight of the selected 
//items does not exceed the knapsack's capacity.

// Problem Statement:
// Write a function int knapsack(int value[], int wt[], int n, int w) that uses recursion to solve
// the 0/1 Knapsack Problem. The function should compute the maximum value that can be obtained by 
//selecting items from the given list, subject to the following conditions:

// You can either include or exclude each item.
// The weight of the selected items must not exceed the knapsack's capacity.
// You must maximize the total value of the selected items.



#include<iostream>
#include<algorithm> 
using namespace std;

int knapsack(int value[], int wt[], int n, int w) {
    // Base Case: If there are no items left or the capacity is 0
    if (n == 0 || w == 0) {
        return 0;
    }

    // If the weight of the current item is greater than the remaining capacity, skip this item
    if (wt[n-1] > w) {
        return knapsack(value, wt, n-1, w);
    }

    // Otherwise, take the maximum of:
    // 1. Excluding the current item
    // 2. Including the current item
    return max(
        knapsack(value, wt, n-1, w), // Exclude current item
        knapsack(value, wt, n-1, w-wt[n-1]) + value[n-1] // Include current item
    );
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int value[n], wt[n];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int w;
    cout << "Enter knapsack capacity: ";
    cin >> w;

    cout << "Maximum value in Knapsack: " << knapsack(value, wt, n, w) << endl;

    return 0;
}
