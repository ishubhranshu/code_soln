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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* dPtr=dummy;
        ListNode* ptr1=list1;
        ListNode* ptr2=list2;

        while(ptr1 && ptr2)
        {
            if(ptr1->val < ptr2->val)
            {
                dPtr->next=ptr1;
                ptr1=ptr1->next;
            }
            else
            {
                dPtr->next=ptr2;
                ptr2=ptr2->next;
            }
            dPtr=dPtr->next;
        }
        if(!ptr1)
            dPtr->next=ptr2;
        else
            dPtr->next=ptr1;

        return dummy->next;
    }
    ListNode* solve(int start, int end, vector<ListNode*>& lists) {
        if(start==end)
            return lists[start];

        int mid=start+(end-start)/2;

        ListNode* left=solve(start, mid, lists);
        ListNode* right=solve(mid+1, end, lists);

        return mergeTwoLists(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
            return nullptr;
        return solve(0, n-1, lists);
    }
};