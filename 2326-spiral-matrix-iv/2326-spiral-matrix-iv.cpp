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
        vector<vector<int>> mat(m, vector<int>(n, -1));

        int left=0, right=n-1, low=m-1, high=0;
        int r=0, c=0;
        ListNode* ptr=head;
        while(ptr && left<=right && high<=low)
        {
            while(c<=right && ptr)
            {
                // cout<<r<<" "<<c<<" "<<ptr->val<<endl;
                mat[r][c]=ptr->val;
                c++;
                ptr=ptr->next;
            }
            high++;
            r++;
            c--;
            while(r<=low && ptr)
            {
                // cout<<r<<" "<<c<<" "<<ptr->val<<endl;
                mat[r][c]=ptr->val;
                r++;
                ptr=ptr->next;
            }
            right--;
            r--;
            c--;
            while(c>=left && ptr)
            {
                // cout<<r<<" "<<c<<" "<<ptr->val<<endl;
                mat[r][c]=ptr->val;
                c--;
                ptr=ptr->next;
            }
            low--;
            r--;
            c++;
            while(r>=high && ptr)
            {
                // cout<<r<<" "<<c<<" "<<ptr->val<<endl;
                mat[r][c]=ptr->val;
                r--;
                ptr=ptr->next;
            }
            left++;
            r++;
            c++;
        }

        return mat; 
    }
};