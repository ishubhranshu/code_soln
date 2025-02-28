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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* ptr=head;
        vector<ListNode*> ans;
        while(ptr)
        {
            n++;
            ptr=ptr->next;
        }

        int minNodes=n/k;
        int extraNodes=n%k;

        ptr=head;
        while(ptr)
        {
            ListNode* nHead=ptr;
            ListNode* prev=nullptr;
            int count=0;
            while(count<minNodes)
            {
                count++;
                prev=ptr;
                ptr=ptr->next;
            }
            if(extraNodes)
            {
                extraNodes--;
                prev=ptr;
                ptr=ptr->next;
            }
            prev->next=nullptr;
            ans.push_back(nHead);
        }
        while(ans.size()<k)
            ans.push_back(nullptr);
        return ans;
    }
};