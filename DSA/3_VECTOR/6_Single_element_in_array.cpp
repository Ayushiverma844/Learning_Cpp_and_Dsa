// PROBLEM: Single Element in a Sorted Array

// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// Example 1:
// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

// Example 2:
// Input: nums = [3,3,7,7,10,11,11]
// Output: 10


#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }
    
    int st = 0, end = n - 1;
    
    while (st <= end) {
        int mid = st + (end - st) / 2;
        
        // Check if mid is the first or last element
        if (mid == 0 && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }
        if (mid == n - 1 && nums[mid] != nums[mid - 1]) {
            return nums[mid];
        }

        // Check if mid is the single element (not paired with neighbors)
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        // Binary search logic
        if (mid % 2 == 0) { // Even index
            if (nums[mid] == nums[mid + 1]) {  // The pair is on the right
                st = mid + 2;
            } else {  // The pair is on the left
                end = mid - 1;
            }
        } else { // Odd index
            if (nums[mid] == nums[mid - 1]) {  // The pair is on the left
                st = mid + 1;
            } else {  // The pair is on the right
                end = mid - 1;
            }
        }
    }
    
    return -1;  // Just in case, but ideally won't be reached
}

int main(){
    vector<int>A = {1,1,2,2,4,4,5,6,6};
    
    //call the function;
    int ans = singleNonDuplicate(A);

    cout<<"Single element is: "<<ans<<endl;
    return 0;
}