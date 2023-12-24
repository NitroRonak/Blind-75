#include<bits/stdc++.h>
using namespace std;

//Problem serialize and deserialize binary tree

class TreeNode{
    public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

string serialize(TreeNode* root) {
    if(root==NULL) return "";
    string str="";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode * currNode=q.front();
        q.pop();
        if(currNode==NULL) str.append("#,");
        else str.append(to_string(currNode->val)+',');
        if(currNode!=NULL){
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return str;
}

TreeNode* deserialize(string data) {
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode * root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode * currNode=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#"){
            currNode->left=NULL;
        }
        else{
            TreeNode* leftNode=new TreeNode(stoi(str));
            currNode->left=leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#"){
            currNode->right=NULL;

        }
        else{
            TreeNode* rightNode=new TreeNode(stoi(str));
            currNode->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void preOrder(TreeNode *root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    
    TreeNode *root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(7);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    serialize(root);
    TreeNode *newRoot=deserialize(serialize(root));
    preOrder(newRoot);
    return 0;
}