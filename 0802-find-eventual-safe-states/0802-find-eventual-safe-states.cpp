class Solution {
public:
    vector<int> safeStates;
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj)
    {
        vis[node]=true;
        pathVis[node]=true;
        
        for(auto neigh: adj[node])
        {
            if(!vis[neigh])
                dfs(neigh, vis, pathVis, adj);

            if(pathVis[neigh])
                return true;
        }
        
        safeStates.push_back(node);
        pathVis[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n, false);
        vector<int> pathVis(n, false);
        
        for(int i=0; i<n; i++)
            if(!vis[i])
                dfs(i, vis, pathVis, adj);
                
        sort(safeStates.begin(), safeStates.end());
        return safeStates;
    }
};