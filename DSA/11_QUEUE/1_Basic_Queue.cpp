#include <iostream>
using namespace std;

// Define a class for Queue
class Queue {
private:
    int front, rear;       // Indices for front and rear of queue
    int arr[5];            // Array to store queue elements (fixed size 5)

public:
    // Constructor to initialize queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to add element to queue
    void enqueue(int value) {
        if (rear == 4) {
            cout << "Queue is FULL!" << endl;
        } else {
            if (front == -1) front = 0;  // First element added
            rear++;
            arr[rear] = value;
            cout << value << " added to the queue." << endl;
        }
    }

    // Function to remove element from queue
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is EMPTY!" << endl;
        } else {
            cout << arr[front] << " removed from the queue." << endl;
            front++;
        }
    }

    // Function to display the queue
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is EMPTY!" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

// Main function
int main() {
    Queue q;

    q.enqueue(10); // Add 10
    q.enqueue(20); // Add 20
    q.enqueue(30); // Add 30

    q.display();   // Show all elements

    q.dequeue();   // Remove one element
    q.display();   // Show remaining elements

    return 0;
}
