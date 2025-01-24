#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class CircularList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize an empty Circular linked list
    CircularList() {
        head = tail = NULL;
    }

    // Function to insert a node at the front of the list
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            // If the list is empty, set both head and tail to the new node
            head = tail = newNode;
            tail->next = head;
            head->prev = tail;
        } else {
            // Insert the new node at the front and adjust the pointers
            newNode->next = head;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at the end of the list
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            // If the list is empty, set both head and tail to the new node
            head = tail = newNode;
            tail->next = head;
            head->prev = tail;
        } else {
            // Insert the new node at the end and adjust the pointers
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    // Function to delete a node at the front of the list
    void pop_front() {
        if (head == NULL) return;
        // single node
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    // Function to delete a node at the end of the list
    void pop_back() {
        if (tail == NULL) return;
        // single node
        if (head == tail) {
            delete tail;
            head = tail = NULL;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            temp->prev = NULL;
            delete temp;
        }
    }

    // Function to print the list from head to tail
    void printList() {
        if (head == NULL) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head); // Continue until we reach the head again
        cout << endl;
    }

    // Function to print the list from tail to head
    void printListReverse() {
        if (tail == NULL) return;
        Node* temp = tail;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail); // Continue until we reach the tail again
        cout << endl;
    }
};

int main() {
    CircularList cl;

    cl.push_front(10);  // Insert 10 at the front
    cl.push_front(20);  // Insert 20 at the front
    cl.push_back(30);    // Insert 30 at the end
    cl.push_back(40);    // Insert 40 at the end
    cl.pop_front();    // Delete 20 from the front
    cl.pop_back();     // Delete 40 from the end

    cout << "List from head to tail: ";
    cl.printList();

    cout << "List from tail to head: ";
    cl.printListReverse();

    return 0;
}

