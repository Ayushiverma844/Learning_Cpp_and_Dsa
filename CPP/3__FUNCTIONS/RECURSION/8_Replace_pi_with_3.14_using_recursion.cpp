#include<iostream>
#include<string>
using namespace std;

// Function to replace pi
void replacePi(string str){

   //base case
    if(str.length()==0){
        return;  
    }

   if((str[0]=='p' && str[1] == 'i') || (str[0]=='P' && str[1] == 'I')){
      cout<<"3.14 ";
      replacePi(str.substr(2));
   }

   else{
    cout<<str[0];
    replacePi(str.substr(1));
   }
}

int main() {
   string s;
   cout<<"Enter string: ";
   getline(cin,s);

 
   cout<<"Replace pi with 3.14: \n ";
 
   //call replace function
   replacePi(s);
   
   cout<<endl;

    return 0;
}
