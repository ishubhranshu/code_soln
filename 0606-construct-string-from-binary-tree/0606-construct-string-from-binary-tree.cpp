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
    void traverse(TreeNode* root, string &s)
    {

        s.push_back('(');
        s+=(to_string(root->val));
        
        if(root->right)
        {
            if(!root->left)
            {
                s.push_back('(');
                s.push_back(')');
            }
            else
                traverse(root->left, s);
            traverse(root->right, s);
        }
        else if(root->left)
            traverse(root->left, s);
        s.push_back(')');
    }
    string tree2str(TreeNode* root) {
        string s="";
        traverse(root, s);
        s.pop_back();
        s=s.substr(1, s.length()-1);
        return s;
    }
};