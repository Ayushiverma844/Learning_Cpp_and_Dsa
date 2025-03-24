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
