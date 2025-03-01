//

#include<iostream>
#include<string.h>
using namespace std;


//Function to convert hexadecimal no to decimal
int hexadecimalTodecimal(string n){
     int ans =0;
     int x = 1;
    
     int s = n.size();  //lenght of string

    for(int i= 0; i<s;i++){
        if(n[i]>'F' || (n[i] >='a' && n[i] <= 'z')){
            cout<<"Wrong input!!\n";
            return 0;
        }
    }
    
    for(int i= s-1; i>=0;i--){
        if(n[i] >='0' && n[i]<='9'){
            ans += x * (n[i]-'0');
        }else if (n[i] >= 'A' && n[i] <='F'){
            ans +=  x * (n[i]-'A' + 10);    //[ex = B - A + 10 == 1 + 10 == 11 ]
        }
        x *= 16;
    }

     return ans;
}



int main(){
    string num;
    cout<<"Give a haxadecimal no: ";
    cin>>num;

    cout<<"Decimal of "<<num<<" is = "<<hexadecimalTodecimal(num);
    cout<<"\n";
    return 0;
}