// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
// Return the index of the peak element.
// Your task is to solve it in O(log(n)) time complexity.

// Example 1:
// Input: arr = [0,1,0]
// Output: 1


#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
     
    // cause we know 1st and last element cannot be peak so for avoiding overflow 
    //from [mid-1]=[0-1] and [mid+1]=[(n-1)+1] we will start from the 2nd and end to 2nd last
    int st = 1, end = arr.size() - 2;

    while (st <= end) {
        int mid = st + (end - st) / 2; // Calculate mid to avoid overflow

        // Check if mid is the peak
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        // If the left side is increasing, move to the right
        else if (arr[mid - 1] < arr[mid]) {
            st = mid + 1;
        }
        // Otherwise, move to the left
        else {
            end = mid - 1;
        }
    }
    return -1; // No peak found (edge case, shouldn't happen for a valid mountain array)
}


int main(){
    vector<int>nums = {3,4,5,6,7,0,1,2};  //mountain array
 
    //call function
    int result = peakIndexInMountainArray(nums);
    
    if(result!=-1){
        cout<<"peak element is "<<nums[result]<<endl;
    }else{
        cout<<"peak not found."<<endl;
    }
  return 0;
}

