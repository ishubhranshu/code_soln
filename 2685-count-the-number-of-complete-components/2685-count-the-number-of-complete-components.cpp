class Solution {
public:
    void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, int &edgeCount, int &vertexCount)
    {
        visited[u]=true;
        vertexCount++;

        for(auto v: graph[u])
        {
            edgeCount++;
            if(!visited[v])
                dfs(v, graph, visited, edgeCount, vertexCount);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n, false);

        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                int edgeCount=0;
                int vertexCount=0;
                dfs(i, graph, visited, edgeCount, vertexCount);
                cout<<i<<" "<<vertexCount<<" "<<edgeCount<<endl;
                if(edgeCount == (vertexCount*(vertexCount-1)))
                    ans++;
            }
        }

        return ans;
    }
};