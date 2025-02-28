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

        ListNode* newHead=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;

        return newHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        ListNode* dummy=new ListNode(-1);
        ListNode* dPtr=dummy;
        
        while(carry || ptr1 || ptr2)
        {
            int sum=carry;
            if(ptr1)
            {
                sum+=ptr1->val;
                ptr1=ptr1->next;
            }
            if(ptr2)
            {
                sum+=ptr2->val;
                ptr2=ptr2->next;
            }

            carry=sum/10;
            sum%=10;

            ListNode* newNode=new ListNode(sum);
            dPtr->next=newNode;
            dPtr=dPtr->next;
        }

        dummy=dummy->next;
        dummy=reverse(dummy);

        return dummy;
        
    }
};