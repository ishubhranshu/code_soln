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

    int minswap(vector<int> &a)
    {
        vector<pair<int, int>> b;

        for(int i=0; i<a.size(); i++)
            b.push_back({a[i], i});

        sort(b.begin(), b.end());

        int swaps=0;
        for(int i=0; i<b.size(); i++)
        {
            if(i!=b[i].second)
            {
                swap(b[i], b[b[i].second]);
                i--;
                swaps++;
            }
        }

        return swaps;
    }
    
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;

        while(!q.empty())
        {
            int n=q.size();
            vector<int> a;
            for(int i=0; i<n; i++)
            {
                TreeNode* node=q.front();
                q.pop();
                
                a.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans+=minswap(a);
        }

        return ans;
    }
};