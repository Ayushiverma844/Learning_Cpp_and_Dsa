#include<iostream>
#include<vector>
using namespace std;

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

// Build tree from preorder with -1 as NULL
Node* buildTree(vector<int>& preorder, int& idx) {
    idx++;
    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

// Check if two trees are identical
bool isSameTree(Node* p, Node* q) {
    if (p == NULL || q == NULL) {
        return p == q;
    }
    return (p->data == q->data) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

// Check if subRoot is subtree of root
bool isSubtree(Node* root, Node* subRoot) {
    if (subRoot == NULL) return true;
    if (root == NULL) return false;

    if (root->data == subRoot->data && isSameTree(root, subRoot)) {
        return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    vector<int> tree1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> tree2 = {3, 4, -1, -1, 5, -1, -1};

    int idx1 = -1;
    Node* root1 = buildTree(tree1, idx1);

    int idx2 = -1;
    Node* root2 = buildTree(tree2, idx2);

    if (isSubtree(root1, root2)) {
        cout << "It is a subtree of the main tree.";
    } else {
        cout << "It is not a subtree.";
    }

    return 0;
}
