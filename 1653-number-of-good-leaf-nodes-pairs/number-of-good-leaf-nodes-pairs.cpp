class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }
    
private:
    vector<int> dfs(TreeNode* node, int distance, int& result) {
        if (!node) return {};
        
        // If it's a leaf node, return a vector with a single distance 1
        if (!node->left && !node->right) {
            return {1};
        }
        
        // Get the distance counts from left and right subtrees
        auto leftDistances = dfs(node->left, distance, result);
        auto rightDistances = dfs(node->right, distance, result);
        
        // Count the good leaf pairs
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) {
                    result++;
                }
            }
        }
        
        // Prepare the distance array for the parent node
        vector<int> newDistances;
        for (int l : leftDistances) {
            if (l + 1 < distance) newDistances.push_back(l + 1);
        }
        for (int r : rightDistances) {
            if (r + 1 < distance) newDistances.push_back(r + 1);
        }
        
        return newDistances;
    }
};
