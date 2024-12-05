
#include<iostream>
using namespace std;

//function to check prime
bool is_prime(int n){
  for(int i=2;i<n;i++){
    if(n%i==0)
      return 0; //false(not prime)
  }
   return 1;   //true(prime)
} 

int main(){
int n;
cout<<"Enter a no: ";
cin>>n;

if(is_prime(n)){
  cout<<""<<n<<" is prime\n";
}else{
  cout<<""<<n<<" is not prime\n";
}

return 0;
}