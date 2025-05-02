// Problem Statement:

// Write a C++ program to find and print the intersection of two integer arrays. The program should:

// Take two predefined arrays arr1 and arr2 of different sizes.

// Find common elements (intersection) between the two arrays.

// Print the common elements only once (no duplicates in output).

// If there are no common elements, print an appropriate message.

// Constraints:

// The arrays contain only integers.

// The array elements are not necessarily sorted.

// The output should avoid printing duplicates even if the same number appears multiple times in the second array.

#include <iostream>
using namespace std;

// Function to find the intersection of two arrays
void intersection(int arr1[], int size1, int arr2[], int size2) {
    bool found = false;
    cout << "Intersection of the two arrays: ";
    
    // Loop through the first array
    for (int i = 0; i < size1; i++) {
        // For each element in arr1, loop through arr2
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                found = true;
                // Mark the element in arr2 as processed by setting it to a sentinel value (e.g., -1)
                arr2[j] = -1; // This prevents duplicates from being printed
                break; // Stop searching once a match is found
            }
        }
    }

    if (!found) {
        cout << "No common elements found.";
    }
    cout << endl;
}

int main() {
    int size1 = 6;
    int arr1[] = {1, 2, 3, 4, 5, 6};

    int size2 = 5;
    int arr2[] = {4, 5, 6, 7, 8};

    // Call the intersection function
    intersection(arr1, size1, arr2, size2);

    return 0;
}