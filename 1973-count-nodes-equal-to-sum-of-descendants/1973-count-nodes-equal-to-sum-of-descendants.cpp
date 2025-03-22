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
    int ans=0;
    int decSum(TreeNode* root)
    {
        if(!root)
            return 0;

        long long left=decSum(root->left);
        long long right=decSum(root->right);

        if(left+right == root->val)
            ans++;

        return left+right+root->val;
    }
    int equalToDescendants(TreeNode* root) {
        decSum(root);
        return ans;
    }
};