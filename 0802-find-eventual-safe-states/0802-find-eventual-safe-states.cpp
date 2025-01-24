class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++)
        {
            for(auto j:graph[i])
                adj[j].push_back(i);
        }

        vector<int> in_deg(n, 0);
        for(auto i: adj)
            for(auto j: i)
                in_deg[j]++;

        queue<int> q;
        for(int i=0; i<n; i++)
            if(in_deg[i]==0)
                q.push(i);

        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i: adj[node])
            {
                in_deg[i]--;
                if(in_deg[i]==0)
                    q.push(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;        
    }
};