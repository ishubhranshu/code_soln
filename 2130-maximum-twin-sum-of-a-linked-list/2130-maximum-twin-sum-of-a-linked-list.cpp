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
    int pairSum(ListNode* head) {
        stack<int> stk;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next)
        {
            stk.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        int ans=0;
        while(slow)
        {
            ans=max(ans, stk.top()+slow->val);
            stk.pop();
            slow=slow->next;
        }

        return ans;
    }
};