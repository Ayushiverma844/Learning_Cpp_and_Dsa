// Problem Statement:

// A student’s grade is rounded according to the following rules:

// If the grade is less than 38, no rounding occurs.
// If the grade is 38 or greater, it is rounded to the nearest multiple of 5 if the difference between the grade and the next multiple of 5 is less than 3.
// Write a function that takes a list of grades and returns a list with the rounded grades according to the rules above.

// Input:

// A list of integers grades, where each integer represents a student's grade.
// Output:

// A list of integers where each grade is rounded according to the specified rules.
// Example:

// Input:
// grades = [73, 67, 38, 33]

// Output:
// [75, 67, 40, 33]

// Explanation:

// 73 is rounded to 75.
// 67 remains the same.
// 38 is rounded to 40.
// 33 remains the same since it is less than 38.

#include <iostream>
#include<vector>
using namespace std;

vector<int> gradingStudents(vector<int> grades) {
    vector<int> ans;

    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] < 38) {
            // No rounding off if grade is less than 38
            ans.push_back(grades[i]);
        } else {
            int nextMultipleOf5 = ((grades[i] / 5) + 1) * 5;
            int difference = nextMultipleOf5 - grades[i];

            // Round off if the difference is less than 3
            if (difference < 3) {
                ans.push_back(nextMultipleOf5);
            } else {
                ans.push_back(grades[i]);
            }
        }
    }

    return ans;
}

// Driver Code
int main() {
    vector<int> grades = {73, 67, 38, 33};
    vector<int> roundedGrades = gradingStudents(grades);

    for (int grade : roundedGrades) {
        cout << grade << " ";
    }

    return 0;
}
