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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=root->val;
        while(!q.empty())
        {
            int n=q.size();
            int nsum=0;
            // cout<<n<<" "<<sum<<" ";
            for(int i=0; i<n; i++)
            {
                TreeNode* node=q.front();
                q.pop();
                node->val=sum-node->val;
                int csum=0;

                if(node->left)
                {
                    q.push(node->left);
                    csum+=node->left->val;
                }
                if(node->right)
                {
                    q.push(node->right);
                    csum+=node->right->val;
                }
                
                if(node->left)
                    node->left->val=csum;
                if(node->right)
                    node->right->val=csum;

                nsum+=csum;
            }
            // cout<<nsum<<endl;
            sum=nsum;
        }

        return root;
    }
};