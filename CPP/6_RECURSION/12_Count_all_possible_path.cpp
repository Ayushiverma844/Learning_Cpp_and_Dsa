//In a board game (ex= snake - ladder)  you can move forward by rolling a die (with numbers 1 to 6). .
// How many path are there to reach at a perticular  point from the given point. 

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