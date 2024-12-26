//PLATEFORM  == GOOGKE KICK START

// Problem: Length of Longest Contiguous Arithmetic Subarray
// Problem Statement:
// Given an array of integers, write a program to find the length of the longest contiguous subarray 
// that forms an arithmetic progression. An arithmetic progression is a sequence of numbers in which 
// the difference between consecutive terms is constant.
//example 1 : 
//[ 2, 4, 6, 8, 10 ] Common difference: +2 ,an airthmetic array
// Example 2:
// [ 100, 90, 80, 70, 60 ] Common difference: -10 , an airthmetic array
// Example 3:
//[3, 5, 7, 10, 15]
//Differences: [2, 2, 3, 5] (changing differences), not an airthmetic array


#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    // Handle case when size is less than 2
    if (size < 2) {
        cout << "Array must have at least 2 elements." << endl;
        return 0;
    }
   
   int a[size];
   
    // Input values
    cout << "Enter " << size << " values: ";
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    
    int ans = 2;  //given minimum lenght of array is 2
    int pd = a[1]-a[0];  //previous diffrence
    int j=2;
    int curr=2;  // Length of current arithmetic subarra

    while(j<size){
        if(pd == a[j]-a[j-1]){
           curr++;
        }
        else{
            pd = a[j]-a[j-1];
            curr=2;  // Reset to 2 since at least two elements will form an arithmetic subarray
        }
        ans = max(curr,ans);
        j++;
    }
    
    cout<<"\n\nLenght of the longest contiguous airthmetic subarrar: \n";
    cout<<ans<<endl;

    return 0;
}


