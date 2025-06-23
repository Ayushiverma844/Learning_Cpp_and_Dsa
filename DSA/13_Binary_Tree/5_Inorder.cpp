//inorder traversal

// Problem Statement:

// You are given the preorder traversal of a binary tree, where -1 represents a NULL node. Your task is to:

// Reconstruct the binary tree from the given preorder traversal.

// Print the inorder traversal of the reconstructed binary tree.

// Input:

// A vector of integers representing the preorder traversal of a binary tree.
// Example: {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}

// Output:

// Print the inorder traversal of the constructed binary tree.

// Constraints:

// Each element in the input vector is either an integer value of a node or -1 for a NULL node.

// The binary tree follows the standard definition: each node has at most two children.

#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;

Node(int val){
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

//inorder
void inorder(Node* root){
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(preorder);

    inorder(root);
    cout<<endl;

    return 0;
}