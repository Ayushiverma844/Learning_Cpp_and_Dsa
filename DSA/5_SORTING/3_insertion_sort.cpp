//  Problem Statement:
// Title: Sort an Array using Insertion Sort

// Objective:
// Write a C++ program to sort an array of integers using the Insertion Sort algorithm. The program should accept input from the user, sort the array in ascending order, and display the sorted array.

// Requirements:

// Ask the user to input the number of elements (size) for the array.

// Accept size number of integer inputs and store them in an array.

// Implement the Insertion Sort algorithm to sort the array in ascending order.

// Print the sorted array as output.

// Constraints:

// The array size must be a positive integer.

// Elements can be both positive and negative integers.

// Sample Input/Output:
// Enter size: 5  
// Enter 5 values: 8 4 2 9 1  
// Sorted array: 1 2 4 8 9  


#include<iostream>
using namespace std;

// Sort the array using insertion sort
void insertion_sort(int arr[], int size) {
    int key, j;
    // Traverse through 1 to size
    for (int i = 1; i < size; i++) {
        key = arr[i];  // Store the current element
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;  // Insert key into the correct position
    }
}

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;
   
   int a[size];
   
    // Input values
    cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    // Call the insertion sort function
    insertion_sort(a, size);

    // Output sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}