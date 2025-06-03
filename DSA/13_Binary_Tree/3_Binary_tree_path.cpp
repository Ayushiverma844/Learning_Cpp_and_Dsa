#include <iostream>
#include <vector>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;
        // Base case: if the current value is -1, it represents a NULL node
    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder); //left
    root->right = buildTree(preorder); //right

    return root;

}


class Solution {
public:
    void allPaths(Node* root, string path, vector<string>& ans) {
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }
        if (root->left) {
            allPaths(root->left, path + "->" + to_string(root->left->data), ans);
        }
        if (root->right) {
            allPaths(root->right, path + "->" + to_string(root->right->data), ans);
        }
    }

    vector<string> binaryTreePaths(Node* root) {
        vector<string> ans;
        if (root == NULL) return ans;

        string path = to_string(root->data);
        allPaths(root, path, ans);
        return ans;
    }
};

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(preorder);

    Solution sol;
    vector<string> paths = sol.binaryTreePaths(root);

    cout << "Root-to-leaf paths:\n";
    for (string s : paths) {
        cout << s << endl;
    }

    return 0;
}
