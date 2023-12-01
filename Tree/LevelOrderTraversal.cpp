#include<bits/stdc++.h>
using namespace std;
//Level Order Traversal of Binary Tree
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
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;  
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node* node=q.front();
            int value=node->data;
            level.push_back(value);
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
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
    vector<vector<int>> ans=levelOrder(root);
    for(auto it:ans){
        for(int i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}