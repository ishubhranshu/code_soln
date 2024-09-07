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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root)
    {
        if(!root)
            return 0;

        if((head->val == root->val && dfs2(head, root)) || !head)
            return 1;

        return dfs(head, root->left) || dfs(head, root->right);
    }

    bool dfs2(ListNode* head, TreeNode* root)
    {       
        if(!head)
            return 1;
        
        if(!root || head->val != root->val)
            return 0;

        return dfs2(head->next, root->left) || dfs2(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root);
    }
};