class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);

        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        vector<int> vis(n, 0);
        vector<double> probs(n, 0);
        
        pq.push({1, start_node});
        probs[start_node]=1;
        

        while(!pq.empty())
        {
            int cnode=pq.top().second;
            double cprob=pq.top().first;
            pq.pop();
            vis[cnode]=1;

            // cout<<cnode<<": "<<endl;
            for(auto nodes: adj[cnode])
            {
                int neigh=nodes.first;
                double prob=nodes.second;
                // cout<<neigh<<" "<<probs[neigh]<<" "<<cprob<<" "<<prob<<endl;
                if(vis[neigh]==1 || probs[neigh]>=cprob*prob)
                    continue;

                probs[neigh]=cprob*prob;
                pq.push({probs[neigh], neigh});
            }
        }

        // for(auto i: probs)
        //     cout<<i<<" ";
        // cout<<endl;

        return probs[end_node];
    }
};