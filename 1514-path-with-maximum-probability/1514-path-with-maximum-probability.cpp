class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        

        vector<vector<pair<int,double>>> adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
        }

        vector<double> prob(n, -1);
        vector<bool> vis(n, 0);
        priority_queue<pair<double, int>> pq;

        // vis[start_node]=1;
        // pq.push({1, start_node});

        // while(!pq.empty())
        // {
        //     int cnode = pq.top().second;
        //     double cprob = pq.top().first;
        //     pq.pop();

        //     if(cnode  == end_node)
        //         return cprob;

        //     for(auto node: adj)
        //     {
        //         int neigh=node[cnode].first;
        //         double neighProb=node[cnode].second;
        //         if(!vis[neigh])
        //         {
        //             vis[neigh]=1;
        //             pq.push({cprob*neighProb, neigh});
        //         }
        //     }
        // }

        return 0;


    }
};