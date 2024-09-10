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
    int gcd(int a, int b)
    {
        if(b==0)    return a;
        return gcd(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!(head->next))
            return head;

        ListNode* ptr=head->next, *prev=head;

        while(ptr)
        {
            int nval=gcd(ptr->val, prev->val);
            ListNode* nnode=new ListNode(nval);
            prev->next=nnode;
            nnode->next=ptr;
            prev=ptr;
            ptr=ptr->next;
        }

        return head;
    }       
};