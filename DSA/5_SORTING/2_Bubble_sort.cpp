//  Problem Statement:
// Title: Sort an Array using Bubble Sort

// Objective:
// Write a C++ program that accepts an array of integers from the user, sorts the array in ascending order using the Bubble Sort algorithm, and displays both the original and sorted arrays.

// Requirements:

// Prompt the user to enter the number of elements (size of the array).

// Read n integer elements from the user and store them in an array.

// Use Bubble Sort to sort the array in ascending order.

// Display the array before and after sorting.

// Constraints:

// The array size n must be a positive integer.

// Elements can include both positive and negative integers.

// Sample Input/Output:
// Enter size : 5  
// Enter value: 9  
// Enter value: 4  
// Enter value: 7  
// Enter value: 1  
// Enter value: 3  

// Entered Elements:  9 4 7 1 3  
// Elements after bubble sort:  1 3 4 7 9  

#include <iostream>
using namespace std;


// Bubble sort implementation
void Bubble_sort(int array[],int size){
   
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-1- i; j++) {
            if (array[j] > array[j + 1]) {
                // Swap elements
                int temp = array[j];
               array[j] =array[j + 1];
               array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    cout<<"Enter size : ";
    cin>>size;
    int a[size];
    int i, j;

    // Input values into the array
    for (i = 0; i < size; i++) {
        cout<<"Enter value: ";
        cin>>a[i];
    }

    // Display the entered elements
    cout<<"Entered Elements: ";
    for (i = 0; i < size; i++) {
        cout<<" "<<a[i];
    }
    cout<<"\n";

    //call function
    Bubble_sort(a,size);
    
    // Display sorted elements
    printf("Elements after bubble sort: ");
    for (i = 0; i < size; i++) {
        cout<<" "<<a[i];
    }
    cout<<"\n";

    return 0;
}