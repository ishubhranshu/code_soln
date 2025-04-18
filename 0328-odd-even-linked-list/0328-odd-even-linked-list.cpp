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

        ListNode* evenHead=head;
        ListNode* oddHead=head->next;
        ListNode* even=head;
        ListNode* odd=head->next;
        
        while(odd && odd->next)
        {
            even->next=even->next->next;
            odd->next=odd->next->next;
            
            even=even->next;
            odd=odd->next;
        }

        even->next=oddHead;    

        return head;
    }
};