//  Problem Statement: Binary Search in a Sorted Array
// Write a C++ program to search a given number in a sorted array using the Binary Search algorithm. If the element is found, return its index; otherwise, return -1.

// Input:
// An integer n representing the size of the array.

// n sorted integers (in increasing order).

// An integer key to search in the array.

// Output:
// If the key is found, display its index.

// If the key is not found, display an appropriate message.

// Example:
// Input:
// Enter size of array: 6  
// Enter elements: 1 3 5 7 9 11  
// Enter value to search: 7

// Output:
// Element found at index: 3

//  Note:
// The array must be sorted before applying binary search.

// Indexing is zero-based.




#include<iostream>
using namespace std;

// Function for binary search
int BinarySearch(int arr[], int size, int key) {
    int s = 0;  // start index
    int e = size - 1;  // end index (size - 1)

    while(s <= e) {
        int mid = (s + e) / 2;  // mid index
        
        if(arr[mid] == key) {
            return mid;  // found the key, return index
        } else if(arr[mid] > key) {
            e = mid - 1;  // search in the left half
        } else {
            s = mid + 1;  // search in the right half
        }
    }
    return -1;  // key not found
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    int key;
    cout << "\nEnter value to search: ";
    cin >> key;
    
    int result = BinarySearch(arr, n, key);
    
    if(result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    
    return 0;
}
