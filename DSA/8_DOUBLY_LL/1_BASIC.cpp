#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyList{
private:
    Node* head;
    Node* tail;
public:
    // Constructor to initialize an empty doubly linked list
    DoublyList(){
        head = tail = NULL;
    }

    // Function to insert a node at the front of the list
    void push_front(int val){
        Node* newNode = new Node(val);
        if (head == NULL) {
            // If the list is empty, set both head and tail to the new node
            head = tail = newNode;
        } else {
            // Insert the new node at the front and adjust the pointers
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at the end of the list
    void push_back(int val){
        Node* newNode = new Node(val);
        if (tail == NULL) {
            // If the list is empty, set both head and tail to the new node
            head = tail = newNode;
        } else {
            // Insert the new node at the end and adjust the pointers
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    // Function to delete a node at the front of the list
    void pop_front(){
        if(head == tail) {
            cout<<"Empty list\n"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        } 
        temp->next = NULL;
        delete temp;
    }

    // Function to delete a node at the end of the list
    void pop_back(){
        if(head == NULL){
            cout<<"Empty list\n"<<endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail!= NULL){
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }

    // Function to print the list from head to tail
    void printList(){
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to print the list from tail to head
    void printListReverse(){
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main(){
    DoublyList dll;
    
    dll.push_front(10);  // Insert 10 at the front
    dll.push_front(20);  // Insert 20 at the front
    dll.push_back(30);    // Insert 30 at the end
    dll.push_back(40);    // Insert 40 at the end
    dll.pop_front();    // Delete 10 from the front
    dll.pop_back();    // Delete 40 from the end

    cout << "List from head to tail: ";
    dll.printList();

    cout << "List from tail to head: ";
    dll.printListReverse();

    return 0;
}
