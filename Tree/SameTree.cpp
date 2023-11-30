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
bool isSameTree(Node* p, Node* q) {
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;
    return p->data==q->data && isSameTree(p->left,q->left) &&
    isSameTree(p->right,q->right);
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
    cout<<isSameTree(root->left,root->right)<<endl;
    return 0;
}