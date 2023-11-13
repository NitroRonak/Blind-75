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

ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL;
    ListNode *curr = head;
    while(curr!= NULL){
        ListNode *nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;
}
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
    ListNode *head=NULL;
    head = insertAtTail(head,1);
    head = insertAtTail(head,2);
    head = insertAtTail(head,3);
    head = insertAtTail(head,4);
    ListNode *ans=reverseList(head);
    while(ans!= NULL){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    return 0;
}