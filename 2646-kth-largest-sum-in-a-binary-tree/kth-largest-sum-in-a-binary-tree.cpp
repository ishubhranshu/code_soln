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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;

        q.push(root);
        // pq.push(root->val);
        // cout<<pq.top()<<endl;
        while(!q.empty())
        {
            int n=q.size();
            long long lsum=0;
            for(int i=0; i<n; i++)
            {
                TreeNode* node=q.front();
                q.pop();

                lsum+=node->val;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            // cout<<lsum<<endl;
            pq.push(lsum);
        }
        while(pq.size()>k)
            pq.pop();
        if(pq.size()==k)
            return pq.top();
        return -1;
    }
};