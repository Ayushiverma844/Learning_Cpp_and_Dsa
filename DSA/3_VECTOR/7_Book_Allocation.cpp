// You are given an array arr[] of integers, where each element arr[i] represents the number 
// of pages in the ith book. You also have an integer k representing the number of students. 
//The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// [12] and [34, 67, 90] Maximum Pages = 191
// [12, 34] and [67, 90] Maximum Pages = 157
// [12, 34, 67] and [90] Maximum Pages = 113.
// Therefore, the minimum of these cases is 113, which is selected as the output.

// Input: arr[] = [15, 17, 20], k = 5
// Output: -1
// Explanation: Allocation can not be done.


// Constraints:
// 1 <=  arr.size() <= 106
// 1 <= arr[i] <= 103
// 1 <= k <= 103 


#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages) {
    int student = 1, pages = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages) {
            return false; // If a book has more pages than maxAllowedPages, return false
        }
        if (pages + arr[i] <= maxAllowedPages) { // Ensure the student can take more books
            pages += arr[i];
        } else {
            student++; // Allocate the next student
            pages = arr[i];
        }
    }
    return student <= m; // If more than m students are needed, return false
}

int allocateBook(vector<int>& arr, int n, int m) {
    if (m > n) {
        return -1; // More students than books
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Calculate the total number of pages
    }

    int ans = -1;
    int st = 0, end = sum;  // Range of possible answers

    while (st <= end) {
        int mid = st + (end - st) / 2; // Middle point of the range

        if (isValid(arr, n, m, mid)) { // Check if it's possible to allocate with maxAllowedPages = mid
            ans = mid;  // Update the answer
            end = mid - 1; // Try for a smaller maxAllowedPages
        } else {
            st = mid + 1; // Try for a larger maxAllowedPages
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 1, 3, 4}; // Array of book pages
    int n = 4, m = 2; // 4 books, 2 students
    
    int result = allocateBook(arr, n, m); // Get the optimal maxAllowedPages
    
    if (result != -1) {
        cout << "Minimum number of pages a student can get: " << result << endl;
    } else {
        cout << "It's not possible to allocate books to students." << endl;
    }

    return 0;
}