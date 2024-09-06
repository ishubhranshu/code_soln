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
    ListNode* deleteMiddle(ListNode* head) {
        
        int n=0;
        ListNode* ptr=head;
        while(ptr)
        {
            ptr=ptr->next;
            n++;
        }
        n=n/2;
        if(n==0)
            return head->next;

        ptr=head;
        ListNode* prev=NULL;

        while(ptr)
        {
            if(n==0)
            {
                if(prev)
                    prev->next=ptr->next;
                    ptr=ptr->next;
            }
            else
            {
                prev=ptr;
                ptr=ptr->next;
            }
            n--;
        }        
        return head;   
    }
};