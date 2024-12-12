//FORM THE BIGGEST NUMBER FRROM THE NUMERIC STRING

#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main() {
    string str ="1235927" ;
 
    cout<<"Given number: "<<str<<endl;
    
    //sort no in decreasing order and we will get biggest no
    //example = 12345  ==> 54321 ==>greatest no

   //using sort function
   
   sort(str.begin(),str.end(),greater<int>());

   cout<<"Biggest number = "<<str<<endl;

   return 0;

}