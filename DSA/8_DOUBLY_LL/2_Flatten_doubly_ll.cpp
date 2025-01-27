//430. Flatten a Multilevel Doubly Linked List
//https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/


#include<iostream>
using namespace std;

// Define the structure for a doubly linked list node
struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int x) : val(x), prev(NULL), next(NULL), child(NULL) {}
};
// Flatten function to flatten the multi-level doubly linked list
    Node* flatten(Node* head) {
        if (head==NULL){
            return head;
        }
    Node * curr = head;
     while(curr != NULL){
    
    //if valid child exist then flatten out the list
    if(curr->child != NULL){
        //flatten the child nodes
         Node * next = curr->next;
         curr->next = flatten(curr->child);
         curr->next->prev = curr;
         curr->child = NULL;
        //find tail
        while(curr-> next != NULL){
            curr = curr->next;
        }

        //attach tail with next ptr
          if(next != NULL){
            curr->next = next;
            next->prev = curr;
          }
    }
    //otherwise update
    curr = curr->next;

 }
 return head;

 }

 // Function to print the doubly linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Create a multi-level doubly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Add a child to the second node
    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    head->next->child->next->prev = head->next->child;

    // Add a child to the child node
    head->next->child->next->child = new Node(6);

    // Print the original list structure
    cout << "Original list structure (flattened list won't show child pointers):" << endl;
    printList(head);

    // Flatten the list
    Node* flattenedList = flatten(head);

    // Print the flattened list
    cout << "Flattened list:" << endl;
    printList(flattenedList);

    return 0;
}
