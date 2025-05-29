#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
       int ans = s1.top();
       s1.pop();
       return ans; 
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;  //  object of queue

    // enqueue operation
    q.push(10);  // Queue: 10
    q.push(20);  // Queue: 10, 20
    q.push(30);  // Queue: 10, 20, 30

    
    cout << "Front element: " << q.peek() << endl;  // Output: 10
    //dequeue operation
    cout << "Removed element: " << q.pop() << endl;  // Removes 10


    cout << "Front after pop: " << q.peek() << endl;  // Output: 20

    
    if (q.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;  // Output: not empty
    }

    return 0;
}
