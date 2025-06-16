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

//check both are same or not
bool isIdentical(Node* p , Node* q){
    if(p== NULL || q== NULL){
        return p == q;
    }
    bool isleftsame = isIdentical(p->left , q->left);
    bool isrightsame = isIdentical(p->right , q->right);

    return isleftsame && isrightsame && p->data == q->data ;
}




int main(){
    vector<int> tree1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int> tree2 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;

    idx = -1;
     Node* root1 = buildTree(tree1);
     idx = -1;
      Node* root2 = buildTree(tree2);
    int ans = isIdentical(root1 , root2);

    if(ans){
        cout<<"Both are same";
    }else{
        cout<<"Not same";
    }
   

    return 0;
}