#include <iostream>
#include <algorithm>  // For the swap function
using namespace std;

// Function to reverse an array by swapping
void reverse(int arr[], int size) {
    int start = 0, end = size - 1;

    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int size = 10;
    int array[size];  
    
    // Store in array
    cout << "\nEnter 10 integers:\n";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    // Print before reversing
    cout << "Before:\n";
    for (int i = 0; i < size; i++) {
        cout << " " << array[i];
    }
    
    // Call the reverse function
    reverse(array, size);
    
    // Print after reversing
    cout << "\nAfter:\n";
    for (int i = 0; i < size; i++) {
        cout << " " << array[i];
    }

    return 0;
}