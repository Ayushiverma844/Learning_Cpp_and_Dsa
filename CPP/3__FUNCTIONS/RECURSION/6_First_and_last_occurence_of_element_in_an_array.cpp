#include<iostream>
using namespace std;

// Function to find first occurrence
int first(int arr[], int size, int i, int key) {
    if (i == size) {
        return -1;  // Key not found
    }
    if (arr[i] == key) {
        return i;  // Return the index of the first occurrence
    }
    return first(arr, size, i + 1, key);  // Recur with the next index
}

// Function to find last occurrence
int last(int arr[], int size, int i, int key) {
    if (i == size) {
        return -1;  // Key not found
    }
    // Recur to find the last occurrence in the remaining array
    int rest = last(arr, size, i + 1, key);
    if (rest != -1) {
        return rest;  // If found in later part, return that index
    }
    if (arr[i] == key) {
        return i;  // Return the index of the last occurrence
    }
    return -1;  // If key is not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    
    cout << "Enter the key to search for: ";
    cin >> key;
    
    int first_occurrence = first(arr, size, 0, key);
    int last_occurrence = last(arr, size, 0, key);
    
    if (first_occurrence != -1) {
        cout << "First occurrence of " << key << " is at index: " << first_occurrence << endl;
    } else {
        cout << key << " not found in the array." << endl;
    }
    
    if (last_occurrence != -1) {
        cout << "Last occurrence of " << key << " is at index: " << last_occurrence << endl;
    } else {
        cout << key << " not found in the array." << endl;
    }
    
    return 0;
}
