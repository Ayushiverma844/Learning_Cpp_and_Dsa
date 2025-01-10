#include <iostream>
using namespace std;

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect if a linked list has a cycle
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // Move slow by one step
        fast = fast->next->next;  // Move fast by two steps

        if (fast == slow) {       // Cycle detected
            return true;
        }
    }
    return false; // No cycle
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

// Utility function to create a cycle in the linked list
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return; // No cycle
    ListNode* current = head;
    ListNode* cycleNode = nullptr;
    int index = 0;

    while (current->next != nullptr) {
        if (index == pos) {
            cycleNode = current;
        }
        current = current->next;
        index++;
    }
    current->next = cycleNode; // Create the cycle
}

int main() {
    int arr[] = {3, 2, 0, -4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create linked list
    ListNode* head = createList(arr, n);

    // Create a cycle (e.g., tail connects to node index 1)
    createCycle(head, 1);

    // Check if the list has a cycle
    if (hasCycle(head)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}
