
#include<iostream>
using namespace std;


//sum of n terms using recurssion

int sum(int n){ 
   if(n==0){
    return 0;
   }

   int prevSum = sum(n-1);
   return n + prevSum ;
}


int main() {
    int n;

    cout<<"Enter no : ";
    cin>>n;

    int result = sum(n); //call function

    cout<<"Sum from 1 to "<<n<<" = "<<result<<endl;
    
    return 0;
}