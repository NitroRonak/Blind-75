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

//Calculates the maximum path sum
//Time complexity:O(n)
//Space complexity:O(n)
int solve(Node* root,int &maxi){
    if(root==NULL) return 0;
    int left=max(0,solve(root->left,maxi));
    int right=max(0,solve(root->right,maxi));
    maxi=max(maxi,left+right+root->data);
    return max(left,right)+root->data;
}
int maxPathSum(Node* root) {
    int maxi = INT_MIN;
    solve(root,maxi);
    return maxi;
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
    cout<<maxPathSum(root)<<endl;
    return 0;
}