//Reverse string using recursion

#include<iostream>
#include<string>
using namespace std;

// Function to reverse string
void reverse(string str){

   //base case
    if(str.length()==0){
        return;  
    }

    string ros = str.substr(1);   //rest of string
    reverse(ros);
    cout<<str[0];
}

  int main() {
    string s;
    cout<<"Enter string: ";
    getline(cin,s);

 
   cout<<"Reverse of "<<s<<" is = "; 
 
   //call reverse function
   reverse(s);
   
   cout<<endl;
   
    return 0;
}
