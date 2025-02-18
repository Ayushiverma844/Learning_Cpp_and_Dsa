// Problem Statement :
// Given an array of integers, the task is to find the previous smaller element for each element in the array. The "previous smaller element" of an element is the element that is smaller than the current element and is located to the left of it in the array. If no smaller element exists, return -1 for that element.

// Example:
// For the array {3, 1, 0, 8, 6}, the output should be {-1, -1, -1, 0, 0} because:

// The previous smaller element of 3 is -1 (no element to the left).
// The previous smaller element of 1 is -1.
// The previous smaller element of 0 is -1.
// The previous smaller element of 8 is 0 (element 0 is smaller and is to the left).
// The previous smaller element of 6 is 0.


#include<iostream>
#include<stack>
#include<vector>
using namespace std;

 vector<int> prevSmallerElement(vector<int>& arr) {
    vector<int> ans(arr.size() , 0) ;
    stack<int> s;

    for(int i=0;i<arr.size();i++) {
        while(s.size() > 0 && s.top() >= arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
     return ans;
 }

 int main() {
    vector<int> arr = {3,1,0,8,6};
    vector<int> result = prevSmallerElement(arr);
    for(int i=0;i<arr.size();i++) {
        cout << " " << result[i] ;
    }
    cout << endl;
    return 0;
 }