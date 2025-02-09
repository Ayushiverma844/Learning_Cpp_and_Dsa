#include<iostream>
#include<vector>
using namespace std;


class stack{
   vector<int> v;

public:
  
  //push function
   void push(int x){
      v.push_back(x);
   }

   //pop function
   void pop(){
     if(!v.empty()){
        v.pop_back();
     }else{
        cout<<"Stack is empty, can't pop\n";
     }
   }

   // top function
   int top(){
     if(!v.empty()){
        return v.back();
     } else{
        cout<<"Stack is empty, can't get top\n";
        return -1;
     }
   }
   
};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"Top element is "<<s.top()<<endl;
    s.pop();
    cout<<"Top element after popping is "<<s.top()<<endl;
    return 0;
}
