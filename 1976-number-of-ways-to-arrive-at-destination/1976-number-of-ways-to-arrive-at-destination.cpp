class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> graph(n);
    
    for(auto &edge: roads) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    
    vector<long long> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    
    int MOD = 1e9 + 7;
    
    // Add a visited array to track processed nodes
    vector<bool> visited(n, false);
    
    while(!pq.empty()) {
        long long cNodeDist = pq.top().first;
        int cNode = pq.top().second;
        pq.pop();
        
        // Skip if we've already processed this node
        if(visited[cNode]) continue;
        
        // Mark as visited
        visited[cNode] = true;
        
        for(auto neighs: graph[cNode]) {
            int neigh = neighs.first;
            long long neighDist = neighs.second;
            long long newNeighDist = cNodeDist + neighDist;
            
            // If not visited and found shorter path
            if(dist[neigh] > newNeighDist) {
                dist[neigh] = newNeighDist;
                ways[neigh] = ways[cNode];
                pq.push({dist[neigh], neigh});
            }
            // If equal distance path found
            else if(dist[neigh] == newNeighDist) {
                ways[neigh] = (ways[neigh] + ways[cNode]) % MOD;
            }
        }
    }
    
    return ways[n-1];
}
};