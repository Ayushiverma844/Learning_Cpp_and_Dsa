// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1


#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int st = 0, end = nums.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2; // Prevent overflow
        if (target == nums[mid]) {
            return mid; // Target found
        }
        // Check if the left half is sorted
        if (nums[st] <= nums[mid]) {

            //check is the target lies in the range
            if (target >= nums[st] && target < nums[mid]) {
                end = mid - 1; // Narrow to left half
            } else {
                st = mid + 1; // Narrow to right half
            }
        }
        // Otherwise, the right half is sorted
        else {
            //check is the target lies in the range
            if (target > nums[mid] && target <= nums[end]) {
                st = mid + 1; // Narrow to right half
            } else {
                end = mid - 1; // Narrow to left half
            }
        }
    }
    return -1; // Target not found
}


int main(){
    vector<int>nums = {3,4,5,6,7,0,1,2};  //rotated sorted array
    int target;
    cout<<"Enter target to search: ";
    cin >> target;

    //call function
    int result = search(nums , target);
    
    if(result!=-1){
        cout<<"target found at "<<result<<" index"<<endl;
    }else{
        cout<<"target not found."<<endl;
    }
  return 0;
}
