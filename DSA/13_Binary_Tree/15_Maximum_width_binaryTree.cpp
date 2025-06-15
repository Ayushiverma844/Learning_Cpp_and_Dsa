#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node definition
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

// Build tree using preorder with -1 as NULL
Node* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

// Function to calculate width of binary tree
int widthOfBinaryTree(Node* root) {
    if (!root) return 0;

    queue<pair<Node*, unsigned long long>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty()) {
        int size = q.size();
        unsigned long long minIndex = q.front().second;
        unsigned long long first, last;

        for (int i = 0; i < size; i++) {
            auto curr = q.front();
            q.pop();
            unsigned long long index = curr.second - minIndex; // Normalize index

            if (i == 0) first = index;
            if (i == size - 1) last = index;

            if (curr.first->left)
                q.push({curr.first->left, 2 * index + 1});
            if (curr.first->right)
                q.push({curr.first->right, 2 * index + 2});
        }

        maxWidth = max(maxWidth, (int)(last - first + 1));
    }

    return maxWidth;
}

// Main function
int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);

    int width = widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree: " << width << endl;

    return 0;
}
