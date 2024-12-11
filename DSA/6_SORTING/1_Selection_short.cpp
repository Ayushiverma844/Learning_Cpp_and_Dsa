
#include<iostream>
using namespace std;

// Function to sort array by selection sort 
void selection_sort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;  // Assume the current index as the minimum
        
        // Inner loop to find the smallest element in the unsorted portion
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted portion
        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int size;

    cout << "Enter size: ";
    cin >> size;
    int array[size];
    
    // Store in array
    cout << "\nEnter " << size << " integers:\n";
    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }
    
    // Call the selection sort function
    selection_sort(array, size);
   
   // Array after sorting
    cout << "\nArray after sorting:\n";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    

    return 0;
}