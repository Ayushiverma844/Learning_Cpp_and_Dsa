
#include<iostream>
#include<string>
using namespace std;

void permutation(string s , string ans){
    
    if(s.length()==0){     //Base case
        cout<<ans<<endl;
        return;
    }

    for(int i=0 ; i<s.length(); i++){

      char ch = s[i];     //fixing character
      string ros = s.substr(0,i) + s.substr(i+1);   //string befor fixed character + string after fixed char

         permutation(ros,ans+ch);     // recursive call
    }

}

int main(){
    string s = "ABC";

    //call function

    permutation(s, " ");

    return 0;
}