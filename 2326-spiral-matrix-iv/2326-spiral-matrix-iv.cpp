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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        ListNode* ptr=head;
        n= ans.size();
        m=ans[0].size();
        int left=0,up=0,down=n-1,right=m-1;
        int curr1=left,curr2=up;
        // vector<int> ans;
        while(left<=right && up<=down)
        {
            while(ptr && curr2<=right && left<=right && up<=down)
            {
                ans[curr1][curr2++]=ptr->val;
                ptr=ptr->next;
            }
            up++;
            curr1=up;
            curr2--;

            while(ptr && curr1<=down && left<=right && up<=down)
            {
                ans[curr1++][curr2]=ptr->val;
                ptr=ptr->next;
            }
            right--;
            curr2=right;
            curr1--;

            while(ptr && curr2>=left && left<=right && up<=down)
            {
                ans[curr1][curr2--]=ptr->val;
                ptr=ptr->next;
            }
            down--;
            curr1=down;
            curr2++;

            while(ptr && curr1>=up && left<=right && up<=down)
            {
                ans[curr1--][curr2]=ptr->val;
                ptr=ptr->next;
            }
            left++;
            curr2=left;
            curr1++;
        }
        return ans;
        return {};

    }
};
