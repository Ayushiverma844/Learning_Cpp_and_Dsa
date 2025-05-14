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