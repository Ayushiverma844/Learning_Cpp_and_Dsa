#include <iostream>
using namespace std;

// Define the ListNode structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* merge2List(ListNode* head1, ListNode* head2) {
        if (head1 == NULL || head2 == NULL) {
            return head1 != NULL ? head1 : head2;
        }

        // Case 1: head1's value is smaller or equal to head2's value
        if (head1->val <= head2->val) {
            head1->next = merge2List(head1->next, head2);
            return head1;
        } else {
            head2->next = merge2List(head1, head2->next);
            return head2;
        }
    }

    // Helper function to print the linked list
    void printList(ListNode* head) {
        ListNode* current = head;
        while (current != NULL) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Helper function to create a linked list from an array
    ListNode* createList(int arr[], int size) {
        ListNode* head = NULL;
        ListNode* temp = NULL;
        for (int i = 0; i < size; i++) {
            ListNode* newNode = new ListNode(arr[i]);
            if (head == NULL) {
                head = newNode;
                temp = head;
            } else {
                temp->next = newNode;
                temp = temp->next;
            }
        }
        return head;
    }
};

int main() {
    Solution solution;

    // Create two linked lists
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    ListNode* head1 = solution.createList(arr1, 4);
    ListNode* head2 = solution.createList(arr2, 4);

    cout << "List 1: ";
    solution.printList(head1);

    cout << "List 2: ";
    solution.printList(head2);

    // Merge the two lists
    ListNode* mergedHead = solution.merge2List(head1, head2);

    cout << "Merged List: ";
    solution.printList(mergedHead);

    return 0;
}
