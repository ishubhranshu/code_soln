class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight: flights)
            adj[flight[0]].push_back({flight[1], flight[2]});
        vector<int> dist(n, INT_MAX);
        dist[src]=0;

        queue<pair<int, int>> pq;
        pq.push({0, src});

        while(!pq.empty())
        {
            int qSize=pq.size();
            while(qSize--)
            {
                int cDist=pq.front().first;
                int node=pq.front().second;
                pq.pop();

                for(auto neigh: adj[node])
                {
                    int neighNode=neigh.first;
                    int neighDist=neigh.second;
                    int newNeighDist=cDist+neighDist;

                    if(dist[neighNode]>newNeighDist)
                    {
                        dist[neighNode]=newNeighDist;
                        pq.push({dist[neighNode], neighNode});
                    }
                }
            }
            k--;
            if(k<0)
                break;
        }

        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};