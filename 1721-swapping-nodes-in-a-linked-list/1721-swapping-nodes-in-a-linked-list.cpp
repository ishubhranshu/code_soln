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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr=head;
        ListNode* first=head;
        ListNode* second=head;
        
        while(--k)
            ptr=ptr->next;

        first=ptr;

        while(ptr->next)
        {
            ptr=ptr->next;
            second=second->next;
        }
        cout<<first->val<<" "<<second->val<<endl;
        swap(first->val, second->val);

        return head;


    }
};