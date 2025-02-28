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
    int solve(ListNode* head)
    {
        if(!head)
            return 0;

        int carry=solve(head->next);
        int prod=head->val*2+carry;
        carry=prod/10;
        prod%=10;

        head->val=prod;

        return carry;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry=solve(head);
        if(carry)
        {
            ListNode* newNode=new ListNode(carry);
            newNode->next=head;
            head=newNode;
        }

        return head;
    }
};