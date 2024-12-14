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