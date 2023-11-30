#include<bits/stdc++.h>
using namespace std;
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
int solve(Node *root){
    if(root==NULL) return 0;
    int left=solve(root->left);
    int right=solve(root->right);
    return max(left,right)+1;
}
int maxDepth(Node* root) {
    return solve(root);
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
    int ans=maxDepth(root);
    cout<<ans<<endl;
    return 0;
}