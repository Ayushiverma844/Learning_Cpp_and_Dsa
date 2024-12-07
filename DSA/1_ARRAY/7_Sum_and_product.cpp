#include <iostream>
#include <algorithm>  // For the swap function
using namespace std;

// Function to calculate the sum of elements
void sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "\nSum of elements of array = " << sum << "\n";
}

// Function to calculate the product of elements
void product(int arr[], int size) {
    int pro = 1; // Initialize to 1 instead of 0
    for (int i = 0; i < size; i++) {
        pro *= arr[i];
    }
    cout << "\nProduct of elements of array = " << pro << "\n";
}

int main() {
    int size = 10;
    int array[size];

    // Store in array
    cout << "\nEnter 10 integers:\n";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    sum(array, size);
    product(array, size);

    return 0;
}
