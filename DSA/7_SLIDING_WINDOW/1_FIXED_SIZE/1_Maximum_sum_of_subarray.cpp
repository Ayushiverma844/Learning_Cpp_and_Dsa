#include <iostream>
#include <vector>
using namespace std;

// Function to calculate maximum sum of subarray of size k
int maxSumSubarray(int arr[], int size, int k) {
    int i = 0, j = 0;
    int sum = 0;
    int maximum = 0;

    // Sliding window technique
    while (j < size) {
        // Add current element to the sum
        sum = sum + arr[j];

        // If window size is less than k, expand the window
        if (j - i + 1 < k) {
            j++;
        }
        // When window size equals k
        else if (j - i + 1 == k) {
            // Update the maximum sum
            maximum = max(maximum, sum);

            // Slide the window forward
            sum = sum - arr[i];
            i++;
            j++;
        }
    }
    return maximum;
}

int main() {
    int n;

    // Accept size of the array
    cout << "Enter size of array: ";
    cin >> n;

    // Array of size n
    int arr[n];

    // Store values in the array
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Accept size of the subarray
    int k;
    cout << "Enter size of subarray: ";
    cin >> k;

    // Handle edge case: if k > n
    if (k > n) {
        cout << "Subarray size cannot be greater than array size!" << endl;
        return 0;
    }

    // Call the function and get the result
    int result = maxSumSubarray(arr, n, k);

    // Output the result
    cout << "Maximum subarray sum = " << result << endl;

    return 0;
}
