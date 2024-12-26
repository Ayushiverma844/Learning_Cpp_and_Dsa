//Amazon question

// Problem Explanation:
// Given an array of integers and a target sum s, you need to find a subarray (a contiguous sequence of elements) whose sum 
//is exactly equal to s. If multiple subarrays satisfy the condition, return the first one you find.

// Input:
// n: The size of the array.
// s: The target sum that we want to achieve.
// A sequence of n integers representing the elements of the array.
// Output:
// If a subarray with sum s exists, output the 1-based indices of the subarray.
// If no such subarray exists, output -1 -1.

// Input:

// 5 12
// 1 2 3 7 5
// Output:
// 2 4
// Explanation:
// The subarray [2, 3, 7] adds up to 12, which is the target sum. Therefore, the program returns the indices of the 
// subarray (1-based): 2 to 4.

#include<iostream>
using namespace std;

int main()
{
   int n, s;
   cout << "Size of array and sum: ";
   cin >> n >> s;
   int a[n];

   // Store elements in the array
   for (int i = 0; i < n; i++) {
       cin >> a[i];
   }

   int i = 0, j = 0, sum = 0;
   int st = -1, en = -1; // Starting and ending indices

   // Expand the window while the sum is less than or equal to the target sum
   while (j < n && sum + a[j] <= s) {
      sum += a[j];
      j++;
   }

   // If we find an exact match for the sum
   if (sum == s) {
      cout << i + 1 << " " << j << endl;
      return 0;
   }

   // Start the sliding window approach
   while (j < n) {
      sum += a[j]; // Expand the window by including a[j]

      // Shrink the window from the left if the sum exceeds the target
      while (sum > s) {
         sum -= a[i];
         i++;
      }

      // If we find a matching subarray
      if (sum == s) {
         st = i + 1; // Store the 1-based index for the start
         en = j + 1; // Store the 1-based index for the end
         break;
      }
      j++; // Move the right pointer
   }

   // If we found the subarray, print the result; otherwise, print -1 -1
   cout << st << " " << en << endl;

   return 0;
}
