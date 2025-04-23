// In a board game like Snake and Ladder, a player moves forward by rolling a die that shows numbers from 1 to 6.

// You are given a starting point and an ending point on the number line. At each move, you can advance your position by any number between 1 and 6 (inclusive).

// Write a program to calculate the total number of distinct ways to reach the ending point from the starting point using valid die rolls.

// Input:
// Starting point s (integer)

// Ending point e (integer), where e >= s

// Output:
// The total number of different paths to reach e from s

// Example:
// Input: 
// Enter starting and ending point: 0 3

// Output:
// There are 4 ways to reach 3 from 0

#include<iostream>
using namespace std;

int count_path(int start , int end){
    
    // Base Case: if we have reached the destination
    if(start == end){
        return 1;
    }

    // Base Case: if we have overshot the destination
    if(start > end ){
        return 0;
    }

     // Initialize count
     int count = 0;

    // Try all possible dice rolls (1 to 6)
    for(int i =1 ; i<=6 ; i++){
        count += count_path(start+i , end);
    }
    return count;
}

int main(){
    
    int s , e;

    cout<<"Enter starting and ending point: ";
    cin>>s>>e;

    // Call the function and get the result
    
    int result = count_path(s, e);

    cout << "There are " << result << " ways to reach " << e << " from " << s << endl;
    
    return 0;
}