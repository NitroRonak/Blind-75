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
bool solve(Node* root,long mindata,long maxdata){
    if(root==NULL) return true;
    if(root->data>=maxdata || root->data<=mindata) return false;
    return solve(root->left,mindata,root->data) &&
            solve(root->right,root->data,maxdata);
}
bool isdataidBST(Node* root) {
    return solve(root,LONG_MIN,LONG_MAX);
}
int main()
{
    return 0;
}