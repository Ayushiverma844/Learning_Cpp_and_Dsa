#include <iostream>
using namespace std;

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the middle node of a linked list
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       // Move slow by one step
        fast = fast->next->next; // Move fast by two steps
    }

    return slow; // Slow pointer will be at the middle node
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

    // Find and print the middle node
    ListNode* middle = middleNode(head);
    cout << "Middle Node Value: " << middle->val << endl;

    return 0;
}
