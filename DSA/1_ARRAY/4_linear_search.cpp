// Problem Statement:
// Write a C++ program to search for a given number in an array of 10 integers entered by the user.
// Implement a linear search algorithm to find the number.

// If the number is found, output the index at which it is located.

// If the number is not found, output -1.
// (Note: Array indexing starts from 0.)


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
    cout<<"Numbeer is present at index = "<<linear_search(array,size,target) <<".\n";

    return 0;
}
