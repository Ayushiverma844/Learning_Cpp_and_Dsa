#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // First, check if there is a cycle using the two-pointer method
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;        // Move slow by one step
            fast = fast->next->next;  // Move fast by two steps

            if (fast == slow) {       // Cycle detected
                // Find the start of the cycle
                slow = head;          // Reset slow to head
                while (slow != fast) { // Move both pointers one step at a time
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;          // The starting node of the cycle
            }
        }

        return NULL;  // No cycle detected
    }
};

int main() {
    // Create nodes
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Link nodes to form a linked list: 3 -> 2 -> 0 -> -4
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create a cycle: fourth node points back to second node
    fourth->next = second; // Uncomment this line to introduce a cycle

    // Detect cycle
    Solution solution;
    ListNode* cycleStart = solution.detectCycle(head);

    if (cycleStart != NULL) {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Cleanup (if no cycle exists, delete nodes to avoid memory leaks)
    // Note: If there's a cycle, cleanup needs special handling
    fourth->next = NULL; // Break the cycle for safe deletion
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
