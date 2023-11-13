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

//Time Complexity : O(n)
//Space Complexity : O(n)
bool hasCycle(ListNode *head) {
    map<ListNode*,bool> mp;
    ListNode *curr=head;
    while(curr!=NULL){
        if(mp[curr]==true){
            return true;
        }
        mp[curr]=true;
        curr=curr->next;
    }
    return false;        
}

//Time Complexity : O(n)
//Space Complexity : O(1)
bool hasCycle_Optimized(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
int main()
{
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=head->next->next;
    cout<<hasCycle_Optimized(head)<<endl;
    return 0;
}