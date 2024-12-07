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