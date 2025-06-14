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

void kth_level(Node* root , int k){
    if(root == NULL) {
        return ;
    }
    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    kth_level(root->left , k-1);
    kth_level(root->right , k-1);

}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(preorder);
   
    int k = 3;

    // print value of node which is at level 3
    kth_level(root , k);
 

    return 0;
}