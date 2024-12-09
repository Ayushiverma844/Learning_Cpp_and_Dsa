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
