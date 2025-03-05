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
    
    pair<int, int> solve(TreeNode* root)
    {
        if(!root) 
            return {0, 1};

        if(!root->left & !root->right)
            return {1, 1};

        auto left=solve(root->left);
        auto right=solve(root->right);
        
        bool isSame=true;
        if(root->left && root->left->val!=root->val)
            isSame=false;
        if(root->right && root->right->val!=root->val)
            isSame=false;

        if(isSame && left.second && right .second)
            return {left.first+right.first+1, 1};

        return {left.first+right.first, 0};
    }
    int countUnivalSubtrees(TreeNode* root) {
        return solve(root).first;    
        
    }
};