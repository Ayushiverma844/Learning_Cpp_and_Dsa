// Problem Statement: Linear Search in an Array
// Write a C++ program to search a specific number in a one-dimensional integer array using linear search. The program should return the index of the number if found, otherwise return -1.

// Input:
// 10 integers to be stored in the array.

// An integer (target) to search in the array.

// Output:
// If the number is found, print the index at which it is found.

// If not found, print that the number is not present.

// Example:
// Input:
// Enter 10 integers:
// 5 8 2 9 1 4 3 6 7 0  
// Enter no to search:  
// 4
// Output:
// Numbeer is present at index = 5.

#include<iostream>
using namespace std;

// Function to search a number in an array
int linear_search(int arr[], int size,int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;  // return index of no if present
        }
    }
    return -1;  //if not present
}

int main() {
    int size = 10;
    int target;
    int array[size];
    
    // Store in array
    cout << "\nEnter 10 integers:\n";
    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }
    
    // search no:
    cout<<"\nEnter no to search: ";
    cin>>target;
    
    //If -1 which means number is not found
     int result = linear_search(array,size,target);

     if(result != -1){
         cout<<"Numbeer is present at index = "<<result <<".\n";
     }
     else{
         cout<<"Numbeer is not found.\n";
     }

    return 0;
}