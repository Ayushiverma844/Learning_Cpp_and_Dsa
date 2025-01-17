#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;   
};

// Create node
struct node* createnewnode(int val) {
    struct node* newnode = new node;  // Using new instead of malloc
    if (newnode == NULL) {
        cout << "Memory allocation failed\n";
        return NULL;
    }
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

// Insert at the beginning
void insert_at_beginning(struct node** head, int val) {
    struct node* temp = new node;  // Using new instead of malloc
    if (temp == NULL) {
        cout << "Memory allocation failed\n";
        return;
    }
    temp->data = val;
    temp->next = *head;
    *head = temp;  // Update the head pointer
}

// Insert at the last
void insert_at_last(struct node* head, int val) {
    struct node* temp = new node;  // Using new instead of malloc
    if (temp == NULL) {
        cout << "Memory allocation failed\n";
        return;
    }
    temp->data = val;
    temp->next = NULL;

    struct node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = temp;
}

// Insert at the middle
void insert_at_mid(struct node** head, int val, int pos) {
    if (pos < 0) {
        cout << "Invalid position.\n";
        return;
    }

    struct node* temp = *head;
    if (pos == 0) {
        insert_at_beginning(head, val);  // Insert at the beginning if position is 0
        return;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position is out of range.\n";
        return;
    }

    struct node* newnode = new node;  // Using new instead of malloc
    newnode->data = val;
    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete node with a specific value
struct node* Delete(struct node* head, int value) {
    while (head != NULL && head->data == value) {
        struct node* temp = head;
        head = head->next;
        delete temp;  // Using delete instead of free
    }

    struct node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            struct node* temp = current->next;
            current->next = current->next->next;
            delete temp;  // Using delete instead of free
        } else {
            current = current->next;
        }
    }

    return head;
}

// Function to count the number of nodes in the linked list
int countNodes(struct node* head) {
    int count = 0;
    struct node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to display the linked list
void Display(struct node* head) {
    cout << "Linked List: ";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Initialize linked list with nodes
    struct node* head = createnewnode(10);
    struct node* node2 = createnewnode(20);
    struct node* node3 = createnewnode(30);
    struct node* node4 = createnewnode(40);
    struct node* node5 = createnewnode(50);

    // Connecting nodes
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Display the initial linked list
    Display(head);

    // Print the number of nodes
    cout << "Number of nodes: " << countNodes(head) << endl;

    // Delete nodes with specific values
    head = Delete(head, 30);  // Call Delete and update head
    head = Delete(head, 50);

    
    cout << "New Linked List after deletions:\n";
    Display(head);
    cout << "Number of nodes: " << countNodes(head) << endl;

    // Insert at beginning, middle, and last
    insert_at_beginning(&head, 0);
    insert_at_mid(&head, 66, 2);
    insert_at_last(head, 90);

    cout << "New Linked List after adding new nodes:\n";
    Display(head);
    cout << "Number of nodes: " << countNodes(head) << endl;

    // Clean up memory (free all nodes)
    struct node* current = head;
    while (current != NULL) {
        struct node* nextNode = current->next;
        delete current;  // Using delete instead of free
        current = nextNode;  // Move to the next node
    }

    return 0;
}