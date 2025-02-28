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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int cumSum=0;
        unordered_map<int, ListNode*> ump;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ump[0]=dummy;
        ListNode* ptr=head;

        while(ptr)
        {
            cumSum+=ptr->val;

            if(ump.find(cumSum) != ump.end())
            {
                ListNode* start=ump[cumSum];
                int tempSum=cumSum;
                ListNode* toDel=start->next;
                
                while(toDel!=ptr)
                {
                    tempSum+=toDel->val;
                    ump.erase(tempSum);
                    toDel=toDel->next;
                }
                start->next=ptr->next;
            }
            else
                ump[cumSum]=ptr;
            ptr=ptr->next;
        }
        return dummy->next;
    }
};