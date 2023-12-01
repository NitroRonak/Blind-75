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
void findInorder(Node* root,vector<int> &inorder){
    if(root==NULL) return;
    findInorder(root->left,inorder);
    inorder.push_back(root->data);
    findInorder(root->right,inorder);
}
int kthSmallest(Node* root, int k) {
    vector<int> inorder;
    findInorder(root,inorder);
    return inorder[k-1];
}

//another approach
void findInorder(Node* root, int& ans, int& cnt, int k) {
    if (root == NULL || cnt >= k) {
        return;
    }
    findInorder(root->left, ans, cnt, k);
    cnt = cnt + 1;
    if (cnt == k) {
        ans = root->data;
        return;
    }
    findInorder(root->right, ans, cnt, k);
}
int kthSmallest(Node* root, int k) {
    int ans=-1;
    int cnt=0;
    findInorder(root,ans,cnt,k);
    return ans;
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
    cout<<kthSmallest(root,2);
    return 0;
}