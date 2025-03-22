// Problem Statement:

// You are given a numeric string str consisting of digits. Your task is to rearrange the digits in such a way that the largest possible number is formed.

// Input:
// A numeric string str (1 ≤ len(str) ≤ 1000), containing only digits (0-9).

// Output:
// Print the largest possible number that can be formed by rearranging the digits in the string.

// Example:

// Input:  "1235927"
// Output: "9755321"

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