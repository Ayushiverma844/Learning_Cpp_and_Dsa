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