

                                  //Pth power of n using recurssion





                                  #include<iostream>
using namespace std;

// Function to calculate power using recursion
int power(int n, int p) {
    // Base case: when power is 0, return 1 (n^0 = 1)
    if (p == 0) {
        return 1;
    }

    // Recursive case: n^p = n * n^(p-1)
    return n * power(n, p - 1);
}

int main() {
    int n, p;

    cout << "Enter number: ";
    cin >> n;
 
    cout << "Enter power: ";
    cin >> p; 

    int result = power(n, p); // Call function to compute power

    cout<<"  "<<n<<" ^ "<<p<<" = "<<result<<endl;
    
    return 0;
}
