#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main() {
    string str ="abABCDieh" ;
    
    cout<<"Given string= "<<str<<endl;
   //transform function
  //transform(first() , last(), where to start(),::toupper/tolower)

    //convert to upper case
   transform(str.begin(),str.end(),str.begin() , :: toupper);
    cout<<"UpperCase = "<<str<<endl;

    //convert to lower case
   transform(str.begin(),str.end(),str.begin() , :: tolower);
    cout<<"LowerCase = "<<str<<endl;

    return 0;
}