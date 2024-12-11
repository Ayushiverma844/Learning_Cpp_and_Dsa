//PLATEFORM  == GOOGKE KICK START

// Your code is counting the number of "record-breaking days" in an array, which refers to days when the record (i.e., the maximum value) is broken compared to previous values, and the current value is greater than the next value in the array.

// To give you an example and help you understand the question you are solving, the problem could be framed as follows:

// Problem: Record Breaking Days
// You are given an array of integers where each element represents the number of visitors (or any measurable quantity) on a particular day. A record-breaking day is defined as a day where the value is strictly greater than the number of visitors on the previous day and also greater than the number of visitors on the following day.

// Write a program that:

// Takes an integer n as input, the number of days (size of the array).
// Takes n integers as input representing the number of visitors for each day.
// Outputs the total number of record-breaking days.

// Additionally:

// The first day can be a record-breaking day if it is greater than the second day.
// The last day can be a record-breaking day if it is greater than the second-last day.

#include<iostream>
using namespace std;

int main()
{
   int n;
   cout<<"Size of array: ";
   cin>>n;
   int a[n+1];
   a[n] = -1; // Sentinel value for the last element

   cout<<"Enter record: ";
   for(int i = 0; i < n; i++) {
       cin>>a[i];
   }

   if (n == 1) {
       cout<<"1"<<endl;
       return 0;
   }

   int ans = 0;
   int mx = -1;

   // Loop through the array and check record-breaking days
   for(int i = 0; i < n; i++) {
       if (a[i] > mx && a[i] > a[i + 1]) {
        //record breaking if a[i] is greater than both previous and next
           ans++;     
       mx = max(mx, a[i]);
   }

   cout << ans << endl;
   return 0;
}
