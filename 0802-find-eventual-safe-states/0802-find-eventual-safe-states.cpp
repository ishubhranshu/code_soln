class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // code here
        
        int n=graph.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++)
        {
            for(auto neigh: graph[i])
                adj[neigh].push_back(i);
        }
        vector<int> inDeg(n, 0);
        vector<int> safeStates;
        

        for(int i=0; i<n; i++)
        {
            for(auto neigh: adj[i])
                inDeg[neigh]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++)
            if(inDeg[i]==0)
                q.push(i);
        int count=0; 
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            safeStates.push_back(node);
            for(auto neigh: adj[node])
            {
                inDeg[neigh]--;
                if(inDeg[neigh]==0)
                    q.push(neigh);
            }
        }
        
        sort(safeStates.begin(), safeStates.end());
        return safeStates;
    }
};