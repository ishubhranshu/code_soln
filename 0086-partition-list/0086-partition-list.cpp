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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lDummy=new ListNode(-1);
        ListNode* rDummy=new ListNode(-1);
        ListNode* lptr=lDummy;
        ListNode* rptr=rDummy;
        ListNode* ptr=head;

        while(ptr)
        {
            if(ptr->val < x)
            {
                lptr->next=ptr;
                lptr=lptr->next;
            }
            else
            {
                rptr->next=ptr;
                rptr=rptr->next;
            }
            ptr=ptr->next;
        }
        rptr->next=nullptr;
        lptr->next=rDummy->next;

        return lDummy->next;
        
        
    }
};