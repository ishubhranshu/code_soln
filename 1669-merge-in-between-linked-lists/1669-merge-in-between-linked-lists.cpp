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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start=nullptr;
        ListNode* end=nullptr;
        
        int count=0;
        ListNode* ptr=list1;
        while(ptr)
        {
            count++;
            if(count==a)
                start=ptr;
            if(count-2==b)
                end=ptr;
            ptr=ptr->next;
        }

        start->next=list2;
        ptr=list2;

        while(ptr && ptr->next)
            ptr=ptr->next;

        if(ptr)
            ptr->next=end;

        return list1;
    }
};