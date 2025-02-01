//hackerrank ques
//ques description = https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

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
