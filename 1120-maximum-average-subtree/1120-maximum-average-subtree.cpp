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
    double maxAvg=-1;
    pair<long long, int> solve(TreeNode* root)
    {
        if(!root)
            return {0, 0};

        auto left=solve(root->left);
        auto right=solve(root->right);

        double avg= (left.first + right.first+ root->val) / ((left.second+right.second+1)*1.0);

        if(avg>maxAvg)
            maxAvg=avg;

        return {left.first + right.first+ root->val, left.second+right.second+1};
    }
    double maximumAverageSubtree(TreeNode* root) {
        solve(root);

        return maxAvg;
    }
};