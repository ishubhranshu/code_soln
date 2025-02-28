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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int count=0;
        int first=-1;
        int last=-1;
        int prevP=-1;
        int minDist=INT_MAX;
        ListNode* ptr=head->next;
        ListNode* prev=head;
        
        while(ptr->next)
        {
            int a=prev->val;
            int b=ptr->val;
            int c=ptr->next->val;

            if((a<b && b>c) || (a>b && b<c))
            {
                cout<<b<<endl;
                if(first==-1)
                    first=count;
                if(prevP!=-1)
                    minDist=min(minDist, count-prevP);
                prevP=count;
                last=count;
            }
            count++;
            prev=ptr;
            ptr=ptr->next;
        }

        if(minDist==INT_MAX)
            return {-1,-1};

        return {minDist, last-first};

    }
};