//430. Flatten a Multilevel Doubly Linked List
//https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/


#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int x) : val(x), prev(NULL), next(NULL), child(NULL) {}
};

Node* flatten(Node* head) {
    if (head == NULL) return head;

    Node* curr = head;
    while (curr != NULL) {
        // If current node has a child, flatten it
        if (curr->child != NULL) {
            Node* next = curr->next;              // Store the next node
            Node* childHead = flatten(curr->child); // Flatten the child list
            
            curr->next = childHead;               // Connect current node to child head
            childHead->prev = curr;
            curr->child = NULL;                   // Remove child pointer
            
            // Move to the tail of the flattened child list
            Node* tail = childHead;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            
            // Connect the tail with the next node, if it exists
            if (next != NULL) {
                tail->next = next;
                next->prev = tail;
            }
        }
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Creating the multi-level doubly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    head->next->child->next->prev = head->next->child;

    head->next->child->next->child = new Node(6);

    cout << "Original list (before flattening):" << endl;
    printList(head);

    Node* flatHead = flatten(head);

    cout << "Flattened list:" << endl;
    printList(flatHead);

    return 0;
}
