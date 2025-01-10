#include <iostream>
using namespace std;

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a singly linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;    // Store the next node
        curr->next = prev;    // Reverse the link
        prev = curr;          // Move prev to the current node
        curr = next;          // Move to the next node
    }
    return prev; // New head of the reversed list
}

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create linked list
    ListNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
