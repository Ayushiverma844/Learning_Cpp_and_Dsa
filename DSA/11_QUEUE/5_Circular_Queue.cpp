#include<iostream>
using namespace std;

class circularQueue{
   int* arr;
   int currSize , cap;
   int f , r ;

   public:
   circularQueue(int size){
    cap = size;
    currSize = 0;
    arr = new int[cap];
    f =0;  r = -1;
   }

   void push(int data){
     if(currSize == cap){
        cout<<"queue is full";
     }
     r = (r+1) % cap ;
     arr[r] = data;
     currSize++;
   }

   void pop(){
      if(empty()){
        cout<<"queue is empty";
      }
      f = (f+1) % cap;
      currSize-- ;
   }

   int front(){
     if(empty()){
        cout<<"queue is empty";
      return -1;  
    } 
      return arr[f];
   }

   bool empty(){
    return currSize==0 ;
   }

   void print(){
    for(int i=0;i< cap;i++){
        cout<< arr[i] <<" ";
    }
    cout<<endl;
   }
};

int main(){
    circularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.print();
    cq.pop();
    cq.push(4);
    cq.print();

    while(!cq.empty()){
       cout<< cq.front() <<" ";
       cq.pop();
    }
     
    
    return 0;
}