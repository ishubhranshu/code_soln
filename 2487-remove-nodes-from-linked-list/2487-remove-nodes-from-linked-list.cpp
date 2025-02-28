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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;

        ListNode* ptr=head;
        while(ptr)
        {
            stk.push(ptr);
            ptr=ptr->next;
        }

        ptr=stk.top();
        stk.pop();
        int mxEle=ptr->val;
        ListNode* result=new ListNode(mxEle);

        while(!stk.empty())
        {
            ptr=stk.top();
            stk.pop();

            if(ptr->val<mxEle)
                continue;
            
            ListNode* node=new ListNode(ptr->val);
            node->next=result;
            result=node;
            mxEle=ptr->val;
        }
        return result;
    }
};