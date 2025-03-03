//

#include<iostream>
using namespace std;

// Function to convert decimal to hexadecimal
string DecimalToHexadecimal(int n) {
    if (n == 0) return "0";  // Special case for 0

    string hex = "";
    char hexChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    // Keep dividing the number by 16 and collect the remainders
    while (n > 0) {
        int remainder = n % 16;
        hex = hexChars[remainder] + hex;  // Prepend the corresponding hex character
        n /= 16;
    }

    return hex;
}

int main() {
    int num;
    cout << "Give a decimal number: ";
    cin >> num;

    cout << "Hexadecimal of " << num << " is = " << DecimalToHexadecimal(num);
    cout << "\n";
    return 0;
}