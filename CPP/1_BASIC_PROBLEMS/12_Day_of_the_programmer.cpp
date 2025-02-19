// The problem is to find the 256th day of a given year. The year can follow one of three calendar systems:

// Julian Calendar (before 1918): Leap years occur every 4 years.
// Gregorian Calendar (after 1918): Leap years occur every 4 years, except for years divisible by 100, unless also divisible by 400.
// Transition Year (1918): The 256th day of the year is on September 26th due to the transition from the Julian to the Gregorian calendar.
// The task is to return the date of the 256th day (Day of the Programmer) for a given year.

#include <iostream>
#include <string>
using namespace std;

string dayOfProgrammer(int year) {
    string ans;

    // Special case for the year 1918 (the transition year from Julian to Gregorian)
    if (year == 1918) {
        ans = "26.09.1918";
    }
    // For years before 1918 (Julian calendar)
    else if (year < 1918) {
        if (year % 4 == 0) {
            // Leap year in Julian calendar
            ans = "12.09." + to_string(year);
        } else {
            // Non-leap year in Julian calendar
            ans = "13.09." + to_string(year);
        }
    }
    // For years after 1918 (Gregorian calendar)
    else {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            // Leap year in Gregorian calendar
            ans = "12.09." + to_string(year);
        } else {
            // Non-leap year in Gregorian calendar
            ans = "13.09." + to_string(year);
        }
    }

    return ans;
}

int main() {
    int year = 2024;  // Example year
    cout << dayOfProgrammer(year) << endl;  // Print the 256th day
    return 0;
}
