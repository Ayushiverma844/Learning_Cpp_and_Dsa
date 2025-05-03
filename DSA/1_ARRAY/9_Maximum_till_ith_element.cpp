// Problem Statement: Maximum Till i
// Write a program that reads an array of integers from the user and prints the maximum element found so far at each position i in the array.

// Input:
// First line: An integer n representing the number of elements in the array.

// Second line: n space-separated integers representing the array elements.

// Output:
// Print n lines, where the i-th line contains the maximum value among the first i+1 elements of the array.

// Example:

// Input:
// 5
// 1 3 2 7 5

// Output:
// 1
// 3
// 3
// 7
// 7
// Explanation:
// max(1) = 1

// max(1, 3) = 3

// max(1, 3, 2) = 3

// max(1, 3, 2, 7) = 7

// max(1, 3, 2, 7, 5) = 7



#include<iostream>
using namespace std;

int main() {
    int size;
     int mx = -1999999;     // any no.
    cout << "Enter size: ";
    cin >> size;

   
   int a[size];
   
    // Input values
    cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    
    cout<<"\n--------------\n";
   //maximum till ith element

   for(int i=0;i<size;i++){
    
    mx = max(mx,a[i]);    //update mx by maximum
    cout<<mx<<"\n";

   }

    return 0;
}