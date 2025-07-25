// Problem Statement:

// You are given the preorder traversal of a binary tree where -1 represents a NULL (i.e., absent) node. Your task is to:

// Reconstruct the binary tree from the given preorder traversal.

// Perform a postorder traversal of the reconstructed binary tree.

// Output the postorder traversal as a space-separated sequence of node values.



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

//postorder
void postorder(Node* root){
    if(root == NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root->data<<" ";

}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(preorder);

    postorder(root);
    cout<<endl;

    return 0;
}