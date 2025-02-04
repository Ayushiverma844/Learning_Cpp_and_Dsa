

#include <iostream>
using namespace std;

string timeConversion(string s) {
    int hours = stoi(s.substr(0, 2));  // Extract the first two characters as an integer

    if (s[8] == 'P' && hours != 12) { 
        hours += 12; // Convert PM time (except 12 PM)
    }
    if (s[8] == 'A' && hours == 12) { 
        hours = 0; // Convert 12 AM to 00
    }

    string new_time = (hours < 10 ? "0" : "") + to_string(hours) + s.substr(2, 6);
    return new_time;
}

int main() {
    string s;
    cin >> s;  // Input time in 12-hour format (e.g., "07:05:45PM")
    
    string result = timeConversion(s);  
    cout << result << endl;  // Output time in 24-hour format
    
    return 0;
}
