#include<iostream>
using namespace std;

// Function for binary search
int BinarySearch(int arr[], int size, int target,int st,int end) {
  
    while(st <= end) {
        int mid = (st + end) / 2;  // mid index
        
        if(arr[mid] == target) {
            return mid;  // found the key, return index
        } else if(arr[mid] > target) {
          //recurssive call
            BinarySearch(arr,size,target,st,mid-1);  // search in the left half
        } else {
          //recurssive call
            BinarySearch(arr,size,target,mid+1,end);  // search in the right half
        }
    }
    return -1;  // target not found
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
    
    int result = BinarySearch(arr, n, key,0,n-1);
    
    if(result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    
    return 0;
}