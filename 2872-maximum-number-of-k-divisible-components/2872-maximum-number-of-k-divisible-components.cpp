class Solution {
public:
    int count=1;
    int solve(int node, vector<vector<int>> &adj, vector<int>& values, int &k, vector<int> &vis)
    {
        vis[node]=1;
        int tchild=0;

        for(auto neigh: adj[node])
        {
            if(vis[neigh])
                continue;
            int child=solve(neigh, adj, values, k, vis);
            // cout<<node<<" "<<child<<endl;
            if(child%k==0)
                count++;

            tchild+=child;
        }

        return tchild+values[node];
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for(auto nodes: edges)
        {
            adj[nodes[0]].push_back(nodes[1]);
            adj[nodes[1]].push_back(nodes[0]);
        }

        solve(0, adj, values, k, vis);

        return count;
    }
};