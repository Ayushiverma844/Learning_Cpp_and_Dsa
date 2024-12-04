//     1
//    212
//   32123
//  4321234
// 543212345

#include<iostream>
using namespace std;

int main(){
    int n = 5;

    // Outer loop for rows
    for(int i = 1; i <= n; i++){
        
        int j;

        // Printing spaces
        for(j = 1; j <= n - i; j++){
            cout << " ";
        }

        // Printing first part of numbers (descending)
        int k = i;
        for(; j <= n; j++){
            cout << k--;
        }

        // Printing second part of numbers (ascending)
        k = 2;
        for(; j <= n + i - 1; j++){
            cout << k++;
        }

        // Move to the next line after printing one row
        cout << "\n";
    }

    return 0;
}