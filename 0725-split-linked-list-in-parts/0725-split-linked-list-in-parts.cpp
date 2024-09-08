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
        vector<ListNode*> ans;
        ListNode* ptr = head;
        int n=0;
        while(ptr)
        {
            n++;
            ptr=ptr->next;
        }
        int m=n;
        int rem = n%k;
        
        // cout<<m<<" "<<endl;
        ptr = head;
        while(m)
        {
            int size=n/k;
            if(rem)
            {
                size++;
                rem--;
            }
            if(!ptr)
                break;
            m-=size;
            ans.push_back(ptr);
            ListNode* prev = NULL;
            while(ptr && size)
            {
                prev=ptr;
                ptr=ptr->next;
                size--;
            }
            prev->next=NULL;
        }
        while(k-ans.size())
            ans.push_back({NULL});
        return ans;
    }
};