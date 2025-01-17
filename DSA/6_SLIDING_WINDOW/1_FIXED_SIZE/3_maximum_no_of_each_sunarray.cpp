#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum of each subarray of size k
vector<int> maxInSubarray(int arr[], int size, int k) {
    int i = 0, j = 0;
    vector<int> ans;

    while (j < size) {
        // If the current window size is less than k, expand the window
        if (j - i + 1 < k) {
            j++;
        }
        // If the window size is exactly k, process the window
        else if (j - i + 1 == k) {
            int maximum = arr[i]; // Start with the first element of the window

            // Find the maximum value in the current window
            for (int idx = i; idx <= j; idx++) {
                if (arr[idx] > maximum) {
                    maximum = arr[idx];
                }
            }

            // Store the maximum in the result
            ans.push_back(maximum);

            // Slide the window
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
    int arr[6] = {1, 2, 3, 4, -5, 6};
    int k;

    // Input size of the subarray
    cout << "Enter size of subarray: ";
    cin >> k;

    // Call the function and get the result
    vector<int> result = maxInSubarray(arr, 6, k);

    // Output the result
    cout << "Maximum of each subarray: ";
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
