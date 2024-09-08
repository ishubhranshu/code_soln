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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0)
            return head;
        int n=0;
        ListNode* ptr = head, *last;

        while(ptr)
        {
            last=ptr;
            ptr=ptr->next;
            n++;
        }
        k%=n;
        // cout<<k<<endl;
        int m=n-k;
        ptr = head;
        ListNode *prev = NULL;

        while(m--)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        if(ptr)
            cout<<prev->val<<" "<<ptr->val;
        if(ptr)
        {
            last->next=head;
            head=ptr;
            prev->next=NULL;
        }
        return head;
    }
};