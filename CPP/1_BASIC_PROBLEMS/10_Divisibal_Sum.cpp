//Input:
// 6 3
// 1 2 3 4 5 6

// Here:
// n = 6: The array contains 6 elements.
// k = 3: We need to check if the sum of pairs is divisible by 3.
// The array ar = {1, 2, 3, 4, 5, 6}.
// Process:
// We will check each pair:

// (1, 2): 1 + 2 = 3, divisible by 3 → count = 1
// (1, 3): 1 + 3 = 4, not divisible by 3
// (1, 4): 1 + 4 = 5, not divisible by 3
// (1, 5): 1 + 5 = 6, divisible by 3 → count = 2
// (1, 6): 1 + 6 = 7, not divisible by 3
// (2, 3): 2 + 3 = 5, not divisible by 3
// (2, 4): 2 + 4 = 6, divisible by 3 → count = 3
// (2, 5): 2 + 5 = 7, not divisible by 3
// (2, 6): 2 + 6 = 8, not divisible by 3
// (3, 4): 3 + 4 = 7, not divisible by 3
// (3, 5): 3 + 5 = 8, not divisible by 3
// (3, 6): 3 + 6 = 9, divisible by 3 → count = 4
// (4, 5): 4 + 5 = 9, divisible by 3 → count = 5
// (4, 6): 4 + 6 = 10, not divisible by 3
// (5, 6): 5 + 6 = 11, not divisible by 3
// Output:
// The total number of valid pairs is 5, so the output would be:5

#include <iostream>
#include <vector>
using namespace std;

int divisibleSumPairs(int n, int k, vector<int>& ar) {
    int count = 0;

    // Iterate through each pair in the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the sum of the pair is divisible by k
            if ((ar[i] + ar[j]) % k == 0) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;  // Read the size of the array and the divisor
    vector<int> ar(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ar[i];  // Read the array elements
    }
    
    // Call the function and print the result
    cout << divisibleSumPairs(n, k, ar) << endl;
    
    return 0;
}
