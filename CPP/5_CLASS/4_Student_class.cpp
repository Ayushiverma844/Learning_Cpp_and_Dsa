#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    int mark[3];  // Member array to store marks

public:
    // Function to input student details
    void Detail() {
        cout << "Enter name: ";
        getline(cin, name);  // Read the full name (including spaces)
        cout << "Enter age: ";
        cin >> age;

        // Read marks for 3 subjects
        for (int i = 0; i < 3; i++) { 
            cout << "\nEnter mark for subject " << (i + 1) << ": ";
            cin >> mark[i];  // Store the marks in the class's mark array
        }
    }

    // Function to calculate the average mark
    float Average() {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += mark[i];  // Access the class member 'mark'
        }
        return sum / 3.0;  // Return the average (float division)
    }

    // Function to display student details
    void Display() {
        cout << "Name of student is: " << name;
        cout << "\nAge of student is: " << age;
        cout << "\nAverage mark is: " << Average();
    }
};

int main() {
    Student obj;
    obj.Detail();  // Input student details
    obj.Display();  // Display student details and average

    return 0;
}
