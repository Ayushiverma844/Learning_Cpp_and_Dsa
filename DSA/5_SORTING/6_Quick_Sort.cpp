#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int st, int end) {
    // Choose the last element as pivot
    int idx = st - 1, pivot = arr[end]; // pivot is the value at the end index

    for (int j = st; j < end; j++) {
        // Compare elements with pivot
        if (arr[j] < pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    // Place pivot at the correct position
    swap(arr[end], arr[idx + 1]); // Now pivot is at idx + 1
    return idx + 1; // Return pivot index
}

void QuickSort(vector<int>& arr, int st, int end) {
    if (st < end) {
        // Call partition function which gives us correct index of pivot
        int pivIdx = partition(arr, st, end);

        // Recursive call for the left half
        QuickSort(arr, st, pivIdx - 1);

        // Recursive call for the right half
        QuickSort(arr, pivIdx + 1, end);
    }
}

int main() {
    vector<int> arr = {12, 31, 35, 8, 32, 17};

    cout << "Given:==>\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    // Call Quick sort 
    QuickSort(arr, 0, arr.size() - 1);

    // Print sorted array
    cout << "After sorting:==>\n";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
