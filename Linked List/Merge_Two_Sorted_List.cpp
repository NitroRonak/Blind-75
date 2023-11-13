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

// Time Complexity: O(n + m)
// Space Complexity: O(n + m) beacuse we are creating new list;
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    while(list1!= NULL && list2!= NULL){
        if(list1->val < list2->val){
            p->next = list1;
            list1 = list1->next;
        }
        else{
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    if(list1!= NULL){
        p->next = list1;
    }
    if(list2!= NULL){
        p->next = list2;
    }
    return head->next;     
}

//----------------------------------------------------------------
// Time Complexity: O(n + m)
// Space Complexity: O(1) because we are just modifying the pointers
// not creating the new list like we did in above approach

ListNode *solve(ListNode *first,ListNode *second){
    if(first->next==NULL){
        first->next=second;
        return first;
    }
    ListNode *curr1=first;
    ListNode *next1=curr1->next;
    ListNode *curr2=second;
    ListNode *next2=curr2->next;
    while(next1!=NULL && curr2!=NULL){
        if((curr2->val>=curr1->val) && (curr2->val<=next1->val)){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    if(list1->val<=list2->val){
        return solve(list1,list2);
    }
    else{
        return solve(list2,list1);
    }
}
int main()
{
    return 0;
}