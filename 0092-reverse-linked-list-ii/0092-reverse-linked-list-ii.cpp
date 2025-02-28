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
    ListNode* reverse(ListNode* head)
    {
        if(!head || !head->next)
            return head;

        ListNode* newHead=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;

        return newHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count=0;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* ptr=dummy;
        ListNode* startPrev=nullptr;
        ListNode* end=nullptr;
        
        while(ptr)
        {
            if(count+1==left)
                startPrev=ptr;
            if(count==right)
                end=ptr;
            count++;
            ptr=ptr->next;
        }
        ListNode* remaining=end->next;
        end->next=nullptr;
        ListNode* start=startPrev->next;
        startPrev->next=reverse(start);
        start->next=remaining;

        return dummy->next;
    }
};