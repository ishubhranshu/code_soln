/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr=head;

        while(--n)
            ptr=ptr->next;

        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(ptr->next)
        {
            prev=curr;
            curr=curr->next;
            ptr=ptr->next;
        }
        if(!prev)
            return head->next;
        
        prev->next=prev->next->next;
        return head;
    }
};