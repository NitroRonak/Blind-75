#include<bits/stdc++.h>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

//Time Complexity:log(n)*k where n is length of vector 
//and k is the length of two linked list

ListNode * mergeTwoList(ListNode* &l1,ListNode* &l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    if(l1->val<=l2->val){
        l1->next=mergeTwoList(l1->next,l2);
        return l1;
    }
    else{
        l2->next=mergeTwoList(l1,l2->next);
        return l2;
    }
    return NULL;
}
ListNode *partitionAndMerge(int s,int e,vector<ListNode*>& lists){
    if(s>e) return NULL;
    if(s==e) return lists[s];
    int mid=s+(e-s)/2;
    ListNode *l1=partitionAndMerge(s,mid,lists);
    ListNode *l2=partitionAndMerge(mid+1,e,lists);
    return mergeTwoList(l1,l2);
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int e=lists.size();
    if(e==0) return NULL;
    return partitionAndMerge(0,e-1,lists);
};


ListNode* insertAtTail(ListNode *&head,int val){
    if(head == NULL){
        return new ListNode(val);
    }
    ListNode *curr = head;
    while(curr->next!= NULL){
        curr = curr->next;
    }
    curr->next = new ListNode(val);
    return head;
}
int main()
{
    ListNode * l1=NULL;
    ListNode * l2=NULL;
    l1=insertAtTail(l1,1);
    l1=insertAtTail(l1,3);
    l2=insertAtTail(l2,2);
    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    ListNode *ans=mergeKLists(lists);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}