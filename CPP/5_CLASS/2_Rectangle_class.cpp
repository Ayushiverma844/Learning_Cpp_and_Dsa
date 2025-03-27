// Problem Statement:

// Create a C++ program that models a rectangle using a class. The program should include the following functionalities:

// Class Definition:

// The class should have private data members for length and width.

// Implement a public method to initialize the dimensions of the rectangle.

// Methods:

// A method to calculate and return the area of the rectangle.

// A method to calculate and return the perimeter of the rectangle.

// Main Function:

// In the main() function, create an object of the Rectangle class.

// Initialize the dimensions of the rectangle with the values 20.0 for length and 30.0 for width.

// Output the area and perimeter of the rectangle.

// The program should display:

// Area of the rectangle.

// Perimeter of the rectangle.

// Sample Output:
// Area of rectangle: 600
// Perimeter of rectangle: 100




#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Method to initialize dimensions
    void initialize(double l, double w) {
        length = l;
        width = w;
    }

    // Method to calculate and return the area
    double area() {
        return length * width;
    }

    // Method to calculate and return the perimeter
    double perimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle obj;
    obj.initialize(20.0, 30.0);
    
    cout << "Area of rectangle: " << obj.area() << endl;
    cout << "Perimeter of rectangle: " << obj.perimeter() << endl;

    return 0;
}
