//  Problem Statement:

// Given a binary tree represented by its preorder traversal where -1 denotes a NULL node, construct the binary tree and then flatten it into a right-skewed linked list in-place, following preorder traversal order.

// Finally, print the flattened tree as a linked list where each node points to the next using the right pointer and the left pointer is set to NULL.

//  Example:

// Input Preorder Traversal:
// {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}

// This represents the binary tree:

//        1
//       / \
//      2   3
//         / \
//        4   5
// After Flattening (Right Skewed Linked List):

// rust
// Copy
// Edit
// 1 -> 2 -> 3 -> 4 -> 5
// Each node points to the next using its right pointer, and all left pointers are NULL.

#include <iostream>
#include <vector>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Global index for buildTree
int idx = -1;

// Function to build tree from preorder
Node* buildTree(vector<int> preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

// Global pointer to keep track of the next node
Node* nextRight = NULL;

// Flatten the tree to a linked list (right-skewed)
void flatten(Node* root) {
    if (root == NULL) return;

    flatten(root->right);
    flatten(root->left);

    root->right = nextRight;
    root->left = NULL;
    nextRight = root;
}

// Function to print the right-skewed linked list
void printFlattened(Node* root) {
    cout << "Flattened Tree (Right Skewed): ";
    while (root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

// Main function
int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    flatten(root);         // Flatten the tree
    printFlattened(root);  // Print the result

    return 0;
}
