//Problem Statement: Employee Salary Management
// You are required to implement a class Employee that performs basic operations related to an employee's salary. The class should allow:

// Input Employee Details:

// The user will enter the employee's name (string), ID (integer), and salary (double).

// The salary cannot be negative. If a negative salary is entered, the program should prompt the user to re-enter a valid salary.

// Increase Salary:

// The user will enter a percentage by which the salary should be increased.

// The percentage increase cannot be negative. If a negative value is entered, the program should prompt the user to enter again.

 
// Display Employee Details:
// Print the name, ID, and updated salary after the increment.

// Constraints:
// The name consists of alphanumeric characters and spaces (no special characters).

// The ID is a positive integer.

// The salary and increment percentage must be non-negative.

// Example Input/Output
// Input 1:
// Enter name: Alice Johnson  
// Enter id: 101  
// Enter salary: 50000  
// Enter percent increase in salary: 10  

// Output 1:
// Name of employee is: Alice Johnson  
// Id of employee is: 101  
// Salary after increase is: 55000  


#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;

public:
    void Detail() {
        cout << "Enter name: ";
        getline(cin,name);
        cout << "Enter id: ";
        cin >> id;
         do {
            cout << "Enter salary: ";
            cin >> salary;
            if (salary < 0) {
                cout << "Salary cannot be negative. Please enter again.\n";
            }
        } while (salary < 0);
    }

     
    void increaseSalary() {
     int percent;
     do {
            cout << "Enter percent increase in salary: ";
            cin >> percent;
            if (percent < 0) {
                cout << "Percent increase cannot be negative. Please enter again.\n";
            }
        } while (percent < 0);
        
     salary = salary * (100+percent)/100 ;
    
    }

    void Display() {
        cout << "Name of employee is: " << name;
        cout << "\nId of employee is: " << id;
        cout << "\nSalary after increase is: " << salary;
    }
};

int main() {
    Employee obj;
    obj.Detail();
    obj.increaseSalary();
    obj.Display();
    
    return 0;
}