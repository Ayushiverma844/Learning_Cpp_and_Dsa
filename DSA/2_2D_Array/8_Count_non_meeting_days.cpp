//Problem Statement:

// You are given a total number of days (days) and a list of meetings, where each meeting is represented as a pair of integers [start, end] indicating the start and end days of the meeting. The meetings may overlap, and you need to determine how many free days remain after accounting for the time occupied by all the meetings.

// A day is considered occupied if it falls within any meeting's start and end dates. Meetings can be merged if they overlap or touch each other. A meeting from day x to day y occupies all days between x and y inclusively.

// Input:
// days (1 ≤ days ≤ 10^5): The total number of days.

// meetings (1 ≤ meetings.length ≤ 10^5): A list of meetings, where each meeting is a pair [start, end], indicating the start and end dates of the meeting (1 ≤ start ≤ end ≤ days).

// Output:
// Return the number of free days, i.e., the number of days that are not occupied by any meeting.

// Example:
// days = 10
// meetings = {{1, 3}, {2, 5}, {7, 8}, {9, 10}}

// Output:
// Number of free days: 4

// Explanation:
// The first two meetings {1, 3} and {2, 5} overlap, so they are merged into one meeting from day 1 to day 5.

// The third meeting {7, 8} occupies days 7 and 8.

// The fourth meeting {9, 10} occupies days 9 and 10.

// Therefore, days 6 and 10 are free, resulting in 4 free days.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort the meetings by start time
        sort(meetings.begin(), meetings.end());

        int meetingDayCount = 0;
        int cur_start = -1, cur_end = -1;

        // Iterate through all meetings
        for(int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0], end = meetings[i][1];
            
            if(start > cur_end) {
                if(cur_end != -1) {
                    // Calculate the number of days occupied by the last set of meetings
                    meetingDayCount += cur_end - cur_start + 1;
                }
                cur_start = start;
                cur_end = end;
            } 
            else {
                // Merge overlapping meetings
                cur_end = max(cur_end, end);
            }
        }   
        
        // Add the last meeting's duration
        if(cur_end != -1) {
            meetingDayCount += cur_end - cur_start + 1;
        }
        
        // Return the number of free days
        return days - meetingDayCount;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Example input: total number of days and the list of meetings
    int days = 10; // Total number of days
    vector<vector<int>> meetings = {
        {1, 3},  // Meeting from day 1 to day 3
        {2, 5},  // Meeting from day 2 to day 5
        {7, 8},  // Meeting from day 7 to day 8
        {9, 10}  // Meeting from day 9 to day 10
    };

    // Call the countDays method and print the result
    int freeDays = solution.countDays(days, meetings);
    cout << "Number of free days: " << freeDays << endl;

    return 0;
}
