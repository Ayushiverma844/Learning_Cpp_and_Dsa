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

// heigth
int height(Node* root){
    if(root == NULL) return 0;

    int leftHg = height(root->left);
    int rightHg = height(root->right);

    return max(leftHg,rightHg)+ 1;

}
int diameterOfBinaryTree(Node* root) {
     if(root == NULL) {
        return 0;
     }
     int l =  diameterOfBinaryTree(root->left);
     int r =  diameterOfBinaryTree(root->right);
     int curr = height(root->left) + height(root->right);

     return max(curr ,max(l,r));
    }

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(preorder);

    // diameter - lenght of longest path between 2 nodes
    cout<<"Height of tree "<< height(root) << endl;
    cout<<"diameter of tree "<<diameterOfBinaryTree(root)<<endl; 


    return 0;
}