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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* left = head;
        ListNode* right = head->next;
        
        while(right)
        {
            // cout<<" "<<head->next->val<<endl;
            int sum = 0;
            while(right->val!=0)
            {
                sum+=right->val;
                right=right->next;
            }
            cout<<sum<<endl;
            left->val = sum;
            right=right->next;
            left->next=right;
            left=left->next;
        }
        // left->next=NULL;
        return head;
    }
};