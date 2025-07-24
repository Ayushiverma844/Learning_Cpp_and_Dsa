class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();  // size of the array

        // Edge case: if only one element, it's the peak
        if(n == 1) return 0;

        // Check if the first element is a peak
        if(arr[0] > arr[1]) return 0;

        // Check if the last element is a peak
        if(arr[n - 1] > arr[n - 2]) return n - 1;

        // Binary Search in the middle elements
        int l = 1, h = n - 2;
        while(l <= h) {
            int mid = l + (h - l) / 2;

            // Check if mid is a peak
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }

            // If mid is less than the next element, move right
            if(arr[mid] < arr[mid + 1]) {
                l = mid + 1;
            } else {
                // Otherwise, move left
                h = mid - 1;
            }
        }

        // Just in case no peak found (should not happen for valid input)
        return -1;
    }
};
