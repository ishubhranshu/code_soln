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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* ptr=head;

        while(ptr)
        {
            stk.push(ptr);
            ptr=ptr->next;
        }
        int k=stk.size()/2;
        ptr=head;
        while(k--)
        {   
            ListNode* temp=ptr->next;
            ptr->next=stk.top();
            stk.top()->next=temp;
            ptr=temp;
            stk.pop();
        }

        ptr->next=nullptr;
        // return head;
    }
};