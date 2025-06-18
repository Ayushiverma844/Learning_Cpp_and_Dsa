// Problem Statement:
// Write a C++ program to build a binary tree from a given preorder traversal array where -1 represents a NULL node, and then count the total number of nodes in the constructed binary tree.

// Example Input:
// Preorder traversal array:
// {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}

// Example Output:
// Total Nodes 5

// Explanation:
// The tree structure from the given input will be:

//         1
//        / \
//       2   3
//          / \
//         4   5
// Number of nodes = 5 (nodes with values 1, 2, 3, 4, 5)


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

// no of nodes
int count(Node* root){
    if(root == NULL) return 0;

    int leftC = count(root->left);
    int rightC = count(root->right);

    return leftC+rightC+ 1;

}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(preorder);

    cout<<"Total Nodes "<< count(root) << endl;

    return 0;
}