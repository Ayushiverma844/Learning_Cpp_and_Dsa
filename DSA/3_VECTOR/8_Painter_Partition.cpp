// Problem
// There is fence which consists of n wooden blocks with each block having a number written on it represented by an array a.
// The painter is also given two numbers l and r. He is given the task to paint the fence using at most
// n colors. But there are certain conditions which the painter must follow while painting:
// He has to paint the fence in sequential manner from left to right i.e, first paint the first block then second block and so on without leaving any block not being painted. 
// He will also use colors in sequential manner i.e, first paint with 1st color,then with 2nd color and so on. Note that he can paint any number of blocks sequentially with a single color and a color once used cannot be reused.
// The sum of numbers written on blocks painted with same color must lie between l and r( both inclusive ).


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedTime) {
    int painter = 1, Time = 0;
    for (int i = 0; i < n; i++) {
        // If current block exceeds maxAllowedTime, return false
        if (arr[i] > maxAllowedTime) {
            return false;
        }
        if (Time + arr[i] <= maxAllowedTime) {
            Time += arr[i];  // Add current block to the current painter's workload
        } else {
            painter++;  // Allocate a new painter
            Time = arr[i];  // Assign the current block to the new painter
            if (painter > m) {
                return false;  // If more than m painters are needed, return false
            }
        }
    }
    return true;  // If it's valid with m painters, return true
}

int minTimeToPaint(vector<int>& arr, int n, int m, int l, int r) {
    if (m > n) {
        return -1; // More painters than blocks, impossible
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];  // Calculate the total sum of block values
    }

    int ans = -1;
    int st = *max_element(arr.begin(), arr.end());  // Start with the largest block size
    int end = sum;  // End with the total sum of all blocks

    while (st <= end) {
        int mid = st + (end - st) / 2;  // Check the middle of the range

        if (isValid(arr, n, m, mid) && mid >= l && mid <= r) {  // Check if it's a valid solution within bounds
            ans = mid;  // Found a valid solution, try to minimize the maximum
            end = mid - 1;  // Try for a smaller max allowed time
        } else {
            st = mid + 1;  // Try for a larger max allowed time
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {40, 30, 10, 20}; // Array of blocks with values
    int n = 4, m = 2; // 4 blocks, 2 painters
    int l = 30, r = 70; // l and r constraints for sum of blocks painted by each painter
    
    int result = minTimeToPaint(arr, n, m, l, r);  // Find the result
    
    if (result != -1) {
        cout << "Minimum time to paint all blocks: " << result << endl;
    } else {
        cout << "It's not possible to paint all blocks with the given constraints." << endl;
    }

    return 0;
}
