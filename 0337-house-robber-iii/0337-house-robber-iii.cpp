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
    
    unordered_map<TreeNode*, int> takeDP;
    unordered_map<TreeNode*, int> ntakeDP;
    
    int solve(TreeNode* root, bool canRob)
    {
        if(!root)
            return 0;

        if(canRob && takeDP.find(root) != takeDP.end())
            return takeDP[root];
        if(!canRob && ntakeDP.find(root) != ntakeDP.end())
            return ntakeDP[root];
        
        int nTake=solve(root->left, true) + solve(root->right, true);
        int take=0;
        if(canRob)
            take=root->val + solve(root->left, false) + solve(root->right, false);

        if(canRob)
            takeDP[root]=max(take, nTake);
        else
            ntakeDP[root]=max(take, nTake);
        
        
        return max(take, nTake);
    }
    int rob(TreeNode* root) {
        return solve(root, true);
    }
};