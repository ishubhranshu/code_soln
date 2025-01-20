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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return head;

        ListNode* even=head;
        ListNode* odd=head->next;
        ListNode* temp=head->next;
        ListNode* prev=NULL;
        
        while(even && odd)
        {
            if(even->next)
                even->next=even->next->next;
            if(odd->next)
                odd->next=odd->next->next;
            
            prev=even;
            even=even->next;
            odd=odd->next;
        }

        even->next=temp;
        return head;
    }
};