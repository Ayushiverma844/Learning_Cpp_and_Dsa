// Problem Statement:
// Write a C++ program that defines a Student class to store and manage details of three students. The class should include attributes for name, age, and gender of each student. Implement member functions to:

// Input student details (name, age, gender) using a loop.

// Display student details in a structured format.
// Ensure that the program correctly handles input, including spaces in names, and properly formats the output.

#include <iostream>
using namespace std;

class Student {
public:
    string name[3];
    int age[3];  
    char gender[3];

    // Function to input student details
    void Detail() {
        for (int i = 0; i < 3; i++) {
            cout << "Enter name of student " << i + 1 << " : ";
            getline(cin, name[i]);  // Read the full name (including spaces)
            cout << "Enter age of student " << i + 1 << " : ";
            cin >> age[i];  // Read the age
            cin.ignore();  // Clear the input buffer to handle newline character after reading age
            cout << "Enter Gender(M/F) of student " << i + 1 << " : ";
            cin >> gender[i];  // Read the age
            cin.ignore();  // Clear the input buffer to handle newline character after reading gender
          
            cout<<"\n";
        }

    }

    // Function to display student details
    void Display() {
        for (int i = 0; i < 3; i++) {
            cout << "Name of student " << i + 1 << " is: " << name[i] << endl;
            cout << "Age of student " << i + 1 << " is: " << age[i] << endl;
            cout << "Gender of student " << i + 1 << " is: " << gender[i] << endl;

            cout<<"\n";
        }
    }
};

int main() {
    Student obj;

    obj.Detail();  // Input student details
    cout<<"\n\n-----------------------------------\n\n";
    obj.Display();  // Display student details

    return 0;
}
