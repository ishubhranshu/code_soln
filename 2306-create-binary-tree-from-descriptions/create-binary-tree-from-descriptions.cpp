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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;
        
        for(auto d:desc)
        {
            int par=d[0];
            int child=d[1];
            int lft=d[2];

            if(mp.find(par)==mp.end())
                mp[par]=new TreeNode(par);

            if(mp.find(child)==mp.end())
                mp[child]=new TreeNode(child);
            
            lft ? mp[par]->left=mp[child] : mp[par]->right=mp[child];

            children.insert(child);
        }
        for(auto i: desc)
            if(children.find(i[0])==children.end())
                return mp[i[0]];
        return NULL;
    }
};