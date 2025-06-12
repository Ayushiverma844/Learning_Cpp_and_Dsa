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

int sumTree(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data += leftSum + rightSum ; 
    return root->data ; 

}
// Inorder traversal to check tree structure
void printInorder(Node* root){
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(preorder);
     cout << "Inorder before sumTree: ";
    printInorder(root);
    cout << endl;

    sumTree(root);

    cout << "Inorder after sumTree: ";
    printInorder(root);
    cout << endl;
    return 0;
}