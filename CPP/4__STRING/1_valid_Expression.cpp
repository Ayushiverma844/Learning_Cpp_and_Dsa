// //Problem Statement:

// Write a program to validate if a given string has balanced parentheses, curly braces, and square brackets. The program should be able to detect whether each opening bracket has a corresponding closing bracket in the correct order.

// Requirements:
// The input is a string consisting of characters such as (), {}, [], and other characters that are not relevant to the validation.
// The program should check if the parentheses, curly braces, and square brackets are balanced:
// For every opening bracket (, {, or [, there should be a corresponding closing bracket ), }, or ].
// The brackets must be properly nested. For example, ({[]}) is valid, but ([)] is not.
// The program should return:
// "valid string" if the string has properly balanced brackets.
// "invalid string" if the string does not have properly balanced brackets.
// Example Inputs and Outputs:
// Example 1:

// Input: ({[()]})
// Output: ({[()]}) is valid string
// Example 2:

// Input: ({[([))}
// Output: ({[([))} is invalid string
// Constraints:
// The maximum size of the input string is 100 characters.
// The string contains only the characters (), {}, [], and other non-bracket characters.
// The program should utilize a stack data structure to ensure the correct order of the brackets and should return the result as per the conditions mentioned.

#include<iostream>
using namespace std;

#define SIZE 100

class Stack{
    public:
        char arr[SIZE];
        int top;

        Stack(){
            top=-1;
        }

    void push(char c){
        if(isFull()){
            return;
        }
        arr[++top]=c;
    }

    char pop(){
        if(isEmpty()){
            return '0';
        }
        return arr[top--];

    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(top>=SIZE-1){
            return true;
        }
        return false;
    }

    void display(){
        int a=top;
        while(a!=-1){
            cout<<arr[a]<<" ";
            a--;
        }
        cout<<endl;
    }

    bool isValid(string s){
        char a;
        
        for(int i=0;i<s.length();i++){
            switch(s[i]){
                case '(':
                case '{':
                case '[':
                    push(s[i]);
                    break;
                case ')':
                    a=pop();
                    if(a!='(' || a=='0'){
                        return false;
                    }
                    break;     
                case '}':
                    a=pop();
                    if(a!='{' || a=='0'){
                        return false;
                    }  
                    break;
                case ']':
                    a=pop();
                    if(a!='[' || a=='0'){
                        return false;
                    }  
                    break;

            }
        }
        if(isEmpty())
            return true;
        else
            return false;
    }

};


int main(){

    Stack obj;
    cout<<"Enter the expresssion :";
    string s;
    cin>>s;

    if(obj.isValid(s))
        cout<<s<<" is valid string \n";
    else
        cout<<s<<" is invalid string \n";

    
    
    return 0;
}