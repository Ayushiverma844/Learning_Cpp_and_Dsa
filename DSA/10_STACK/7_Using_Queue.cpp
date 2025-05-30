#include<iostream>
#include<Queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack stack;

    // Push elements onto the stack
    stack.push(10);   // Stack: 10
    stack.push(20);   // Stack: 20 (top), 10
    stack.push(30);   // Stack: 30 (top), 20, 10

    // Get top element
    cout << "Top element: " << stack.top() << endl; // Output: 30

    // Pop top element
    cout << "Popped element: " << stack.pop() << endl; // Removes 30

    // Check top after pop
    cout << "Top element after pop: " << stack.top() << endl; // Output: 20

    // Check if stack is empty
    if (stack.empty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
