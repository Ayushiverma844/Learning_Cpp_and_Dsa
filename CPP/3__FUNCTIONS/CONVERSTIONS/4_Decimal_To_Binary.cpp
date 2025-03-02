//

#include<iostream>
using namespace std;

// Function to convert decimal to binary
int DecimalToBinary(int n){
    int ans = 0;
    int x = 1;  // x will represent the current power of 2

    // Find the largest power of 2 less than or equal to n
    while (x <= n) {
        x *= 2;
    }

    // Now x is the smallest power of 2 greater than n, so we go one step back
    x /= 2;

    // Generate the binary representation
    while (x > 0) {
        int lastdigit = n / x;
        n -= lastdigit * x;
        x /= 2;
        ans = ans * 10 + lastdigit;
    }

    return ans;
}

int main(){
    int num;
    cout << "Give a decimal no: ";
    cin >> num;

    cout << "Binary of " << num << " is = " << DecimalToBinary(num);
    cout << "\n";
    return 0;
}