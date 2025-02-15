#include<iostream>
#include<stack>
using namespace std;

// function to check is the string contain valid parentheses
bool isValid(string str){
    stack<char> s;
    // iterate through each character in the string
    for(char c : str){
        // if the character is an opening parenthesis, push it onto the stack
        if(c == '(' || c == '{' || c == '['){
            s.push(c);
        }
        // if the character is a closing parenthesis, check if the stack is empty
        else if(c == ')' || c == '}' || c == ']'){
             // if the stack is empty, the string is not valid
            if(s.empty()) return false;
             // if the stack is not empty, compare the closing parenthesis with the top of the stack
            // if they don't match, the string is not valid
            char top = s.top();

            s.pop();
            if((c == ')' && top!= '(') || (c == '}' && top!= '{') || (c == ']' && top!= '[')){
                return false;
            }
        }
    }
    // if the stack is empty at the end of the loop, the string is valid
    return s.empty();
}

int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;
    // check if the string is valid or not
    if(isValid(str))
        cout << "The string is valid." << endl;
    else
        cout << "The string is not valid." << endl;
    return 0;
}