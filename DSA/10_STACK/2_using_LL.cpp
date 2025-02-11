                        // Stack using linked list
#include<iostream>
#include<list>
using namespace std;


class stack{
   list<int> ll;

public:
  
  //push function
   void push(int x){
      ll.push_front(x);
   }

   //pop function
   void pop(){
     if(!ll.empty()){
        ll.pop_front();
     } else{
        cout<<"Stack is empty, can't pop\n";
     }
   }

   // top function
   int top(){
      if(!ll.empty()){
        return ll.front();
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
