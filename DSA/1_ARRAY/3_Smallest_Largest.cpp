#include<iostream>
using namespace std;

// Function to find smallest number in an array
int smallest(int arr[], int size) {
    int x = arr[0];  // Initialize x to the first element
    for(int i = 1; i < size; i++) {
        if(arr[i] < x) {
            x = arr[i];  // Update x if a smaller number is found
        }
    }
    return x;
}

// Function to find largest number in an array
int largest(int arr[], int size) {
    int x = arr[0];  // Initialize x to the first element
    for(int i = 1; i < size; i++) {
        if(arr[i] > x) {
            x = arr[i];  // Update x if a larger number is found
        }
    }
    return x;
}

int main() {
    int size = 10;
    int array[size];
    
    // Store in array
    cout << "\nEnter 10 integers:\n";
    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }
    
    // Print the entered numbers
    cout << "You entered:\n";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
    
    // Display smallest and largest number
    cout << "Smallest number = " << smallest(array, size) << "\n";
    cout << "Largest number = " << largest(array, size) << "\n";

    return 0;
}
