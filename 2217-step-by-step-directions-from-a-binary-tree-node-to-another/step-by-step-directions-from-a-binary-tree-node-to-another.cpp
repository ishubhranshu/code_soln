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
    TreeNode* lca(TreeNode* root, int p, int q)
    {
        if(!root)
            return NULL;

        TreeNode* l =lca(root->left, p, q);
        TreeNode* r =lca(root->right, p, q);

        if(root->val == p || root->val == q)
            return root;

        if(l && r)
            return root;
        if(l)
            return l;

        return r;
    }
    bool finp(TreeNode* root, int s, string &lts)
    {
        if(!root)
            return 0;

        if(root->val==s)
            return 1;

        lts+='L';
        if(finp(root->left, s, lts))
            return 1;
        lts.pop_back();

        lts+='R';
        if(finp(root->right, s, lts))
            return 1;
        lts.pop_back();

        return 0;
    }
    string getDirections(TreeNode* root, int s, int d) {
        TreeNode *lcan=lca(root, s, d);
        string lts="", ltd="";

        finp(lcan, s, lts);
        finp(lcan, d, ltd);

        for(int i=0; i<lts.size(); i++)
            lts[i]='U';

        return lts+ltd;

    }
};