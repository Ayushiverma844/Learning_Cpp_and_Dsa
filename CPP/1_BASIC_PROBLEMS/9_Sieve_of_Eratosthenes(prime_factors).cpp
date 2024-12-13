//Find all prime factors of n using SIEVE EROTOSTHENES METHOD

#include<iostream>
using namespace std;

void prime_factor_Sieve(int n) {
    int spf[n + 1] ;  // Spf = smallest prime factor 

// Initialize the spf array such that each number is its own smallest prime factor
    for(int i=2;i<=n;i++){
        spf[i] = i;
    }
    
    // Use Sieve of Eratosthenes to calculate the smallest prime factor (spf) for each number
    for(int i=2;i<=n;i++){
        if(spf[i] ==i){    // i is a prime number
            for(int j = i*i ; j<=n ; j+=i){
                if(spf[j]==j){    // If spf[j] has not been updated
                    spf[j] = i;   // Mark the smallest prime factor of j as i
                }
            }
        }
    }

// Output the prime factors of n
    while(n!=1){
        cout<<spf[n]<<" ";   // Print the smallest prime factor of n
        n = n/spf[n];      // Divide n by its smallest prime factor
    }
   
}


int main() {
    int n;
    cout << "Enter a number : ";
    cin >> n;

  cout<<"All prime factor of "<<n<<" :\n";
    prime_factor_Sieve(n); // Call the sieve function to print all prime factor

    return 0;
}
