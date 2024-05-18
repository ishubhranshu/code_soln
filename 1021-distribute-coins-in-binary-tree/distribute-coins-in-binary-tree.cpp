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

    void distribute(TreeNode* root, TreeNode* par, int &count)
    {
        if(!root)
            return;

        distribute(root->left, root, count);
        distribute(root->right, root, count);
        if(root->val > 1 && par!=NULL)
        {
            int extracoins = root->val-1;
            root->val=1;
            par->val+=extracoins;
            count+=extracoins;
        }
        if(root->val < 1 && par!=NULL)
        {
            int neededcoins = 1-root->val;
            root->val+=neededcoins;
            par->val-=neededcoins;
            count+=neededcoins;
        }
    }
    int distributeCoins(TreeNode* root) {
        int cnt=0;
        distribute(root, NULL, cnt);
        return cnt;
    }
};