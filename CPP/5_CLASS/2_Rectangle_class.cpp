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
