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
void reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return; // No need to reorder if the list has 0, 1, or 2 nodes
    }
    // Find the middle of the list using the slow and fast pointer approach
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Reverse the second half of the list
    ListNode *reversed = reverseList(slow->next);
    slow->next = NULL; // Cut off the original list
    // Merge the two halves
    ListNode *p1 = head;
    ListNode *p2 = reversed;
    while (p2 != NULL) {
        ListNode *temp1 = p1->next;
        ListNode *temp2 = p2->next;
        p1->next = p2;
        p2->next = temp1;
        p1 = temp1;
        p2 = temp2;
    }
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
    reorderList(head);
    while(head!= NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}