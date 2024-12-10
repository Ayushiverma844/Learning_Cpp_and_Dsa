#include<iostream>
using namespace std;

//function to calculate factorial
int fact(int n){
  int f =1;
  for(int i=1;i<=n;i++){
    f*=i;
  }
  return f;
}

//function to calculate combination
int Comb(int n,int r){
   int c;
   c = fact(n)/ (fact(r)*fact(n-r));   //nCr = n!/r!( n-r)!
   return c; 
}


int main(){
int n,r;
cout<<"Enter value = ";
cin>>n>>r;

if(r>n){
      cout<<"ERROR!!!";
      return 0;
    }

else if(n<0){
      cout<<"ERROR!!!";
      return 0;
}

else{
    cout<<"Combination of "<<n<<" and "<<r<<" = "<<Comb(n,r);
}
  return 0;      
       
}