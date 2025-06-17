// Problem Statement:

// Write a C++ program to build a binary tree from a given preorder traversal array where -1 represents a NULL node. 
// Implement a function that constructs the binary tree using recursion, and then display 
// the root, left child, and right child values of the constructed binary tree.

// Example:

// Given preorder traversal array:
// {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}

// This represents the following binary tree:

//         1
//        / \
//       2   3
//          / \
//         4   5

// Explanation:

// 1 is the root.

// 2 is the left child of 1.

// -1, -1 means 2 has no left or right children.

// 3 is the right child of 1.

// 4 is the left child of 3.

// -1, -1 means 4 has no children.

// 5 is the right child of 3.

// -1, -1 means 5 has no children.

// Output:
// 1
// 2
// 3


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

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(preorder);

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;

    return 0;
}