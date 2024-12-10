
#include<iostream>
using namespace std;

// Function to convert decimal to octal
int DecimalToOctal(int n){
    int ans = 0;
    int x = 1;  // x will represent the current power of 8

    // Find the largest power of 8 less than or equal to n
    while (x <= n) {
        x *= 8;
    }

    // Now x is the smallest power of 8 greater than n, so we go one step back
    x /= 8;

    // Generate the octal representation
    while (x > 0) {
        int lastdigit = n / x;
        n -= lastdigit * x;
        x /= 8;
        ans = ans * 10 + lastdigit;
    }

    return ans;
}

int main(){
    int num;
    cout << "Give a decimal no: ";
    cin >> num;

    cout << "Octal of " << num << " is = " << DecimalToOctal(num);
    cout << "\n";
    return 0;
}
