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
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next)
            return head;

        ListNode* newNode=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;

        return newNode;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;

        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(fast)
            slow=slow->next;
        prev->next=reverse(slow);
        
        slow=head;
        fast=prev->next;

        while(fast)
        {
            if(slow->val != fast->val)
                return false;
            slow=slow->next;
            fast=fast->next;
        }

        return true;
    }
};