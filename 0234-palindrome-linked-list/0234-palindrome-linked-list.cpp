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
    ListNode* tail;
    bool solve(ListNode* head)
    {
        if(!head)
            return true;

        bool ans=solve(head->next);
        if(head->val != tail->val)
            return false;
        tail=tail->next;
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        tail=head;
        return solve(head);
    }
};