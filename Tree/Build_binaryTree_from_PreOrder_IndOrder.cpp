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

//Construct binary tree from preorder and inorder

Node *solve(vector<int>& pre, vector<int>& in,int &index,
        int startIn,int endIn,map<int,int> &indexTOmap,int n)
{
    if(index>=n || startIn>endIn) return NULL;
    int element=pre[index++];
    Node *root=new Node(element);
    int pos=indexTOmap[element];
    root->left=solve(pre,in,index,startIn,pos-1,indexTOmap,n);
    root->right=solve(pre,in,index,pos+1,endIn,indexTOmap,n);
    return root;
}
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preOrderIndex=0;
    int n=inorder.size();
    map<int,int> indexTOmap;
    for(int i=0;i<n;i++){
        indexTOmap[inorder[i]]=i;
    }
    return solve(preorder,inorder,preOrderIndex,0,n-1,indexTOmap,n);
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
    return 0;
}