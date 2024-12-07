#include <iostream>
#include <algorithm>  // For the swap function
using namespace std;

// Function to swap maximum and minimum numbers in an array
void swap_max_and_min(int arr[], int size) {
    int min = arr[0], max = arr[0]; // Initialize min and max to the first element
    int ind_min = 0, ind_max = 0; // Initialize indices for min and max
    
    // Find both min and max in one pass
    for (int i = 1; i < size; i++) { // Start from 1 because min/max are already set to arr[0]
        if (arr[i] < min) {
            min = arr[i];
            ind_min = i;  // Update index of min
        }
        if (arr[i] > max) {
            max = arr[i];
            ind_max = i;  // Update index of max
        }
    }

    // Swap the minimum and maximum elements
    swap(arr[ind_max], arr[ind_min]);
}

int main() {
    int size = 10;
    int array[size];

    // Store in array
    cout << "\nEnter 10 integers:\n";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    // Print before swapping
    cout << "Before:\n";
    for (int i = 0; i < size; i++) {
        cout << " " << array[i];
    }
    
    // Call the swap function
    swap_max_and_min(array, size);
    
    // Print after swapping
    cout << "\nAfter:\n";
    for (int i = 0; i < size; i++) {
        cout << " " << array[i];
    }

    return 0;
}
