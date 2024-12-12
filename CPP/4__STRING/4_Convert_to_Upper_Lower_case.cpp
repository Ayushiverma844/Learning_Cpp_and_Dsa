#include <iostream>
#include <string>
using namespace std;

int main() {
    string str ="abABCDieh" ;
    
    cout<<"Given string= "<<str<<endl;
    //convert to upper case
    //'a' - 'A' = 32

  for(int i=0;i<str.size();i++){
      if(str[i] >='a' && str[i] <= 'z'){
        str[i] -= 32;
      }
    } 

    cout<<"UpperCase =  "<<str<<endl;

    //convert to lower case
 for(int i=0;i<str.size();i++){
      if(str[i] >='A' && str[i] <= 'Z'){
        str[i] += 32;
      }
    } 
    cout<<"LowerCase = "<<str<<endl;

    return 0;
}