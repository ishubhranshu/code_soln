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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto i: nums)
            st.insert(i);

        while(head && st.find(head->val)!=st.end())
                head=head->next;

        ListNode* ptr=head;
        ListNode* prev=NULL;
        while(ptr)
        {
            if(st.find(ptr->val)!=st.end())
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
        }
        return head;
    }
};