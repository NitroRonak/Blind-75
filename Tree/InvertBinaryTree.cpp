#include<bits/stdc++.h>
using namespace std;
//Problem :
//226. Invert Binary Tree
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void solve(Node *root){
    if(root==NULL) return;
    swap(root->left,root->right);
    solve(root->left);
    solve(root->right);
}
Node *invertTree(Node *root){
    solve(root);
    return root;
}
int main()
{
    Node *root=new Node(1);
    root->left = new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->right=new Node(7);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    Node *ans=invertTree(root);
    return 0;
}