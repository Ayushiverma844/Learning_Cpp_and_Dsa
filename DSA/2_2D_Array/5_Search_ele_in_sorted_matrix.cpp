// Question: Search in Sorted 2D Matrix
// You are given a 2D matrix where:
// Each row is sorted in ascending order from left to right.
// Each column is sorted in ascending order from top to bottom.

                   //BRUTE FORCE APPROACH

#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout << "Enter size of row and coloumn: ";
    cin >> n>>m;
    int a[n][m];   
    bool found = false;

    // Store elements in 1st matrix
    cout << "Enter values of 1st matrix: ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    int target;
    cout<<"Enter target value to search: " ;
    cin>>target;

    int r=0 , c=m-1;   // Start from top-right corner

    while(r<n && c>=0){
        if(a[r][c] == target){
            found = true;
            break;  // Exit the loop once the target is found
        }
        if(a[r][c] > target){
            c--;   // Move left if the target is smaller
        }else{
            r++;   // Move down if the target is larger
        }
    }
    
      // Output the result
       if(found){
        cout<<"element found.";
       }else{
        cout<<"Element does not exit.";
       }
    return 0; 
}
