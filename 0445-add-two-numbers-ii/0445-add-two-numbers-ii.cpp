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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        stack<int> stk1;
        stack<int> stk2;
        
        while(ptr1)
        {
            stk1.push(ptr1->val);
            ptr1=ptr1->next;
        }
        while(ptr2)
        {
            stk2.push(ptr2->val);
            ptr2=ptr2->next;
        }
        ListNode* dummy=nullptr;
        
        while(carry || !stk1.empty() || !stk2.empty())
        {
            int sum=carry;
            if(!stk1.empty())
            {
                sum+=stk1.top();
                stk1.pop();
            }
            if(!stk2.empty())
            {
                sum+=stk2.top();
                stk2.pop();
            }

            carry=sum/10;
            sum%=10;

            ListNode* newNode=new ListNode(sum);
            newNode->next=dummy;
            dummy=newNode;
        }


        return dummy;
        
    }
};