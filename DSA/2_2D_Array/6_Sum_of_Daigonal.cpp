#include<iostream>
#include<algorithm>
using namespace std;

int sumOfDaigonal(int arr[][3], int n) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // Primary diagonal
            if (i == j) {
                sum += arr[i][j];
            }
            // Secondary diagonal, but only if it's not already counted
            else if (j == n - 1 - i) {
                sum += arr[i][j];
            }
        }
    }

    return sum;
}

int main() {
    int arr[3][3] = {{11, 22, 33}, {10, 20, 30}, {1, 2, 3}};   

    cout << "Sum of Diagonals = " << sumOfDaigonal(arr, 3);

    return 0;
}
