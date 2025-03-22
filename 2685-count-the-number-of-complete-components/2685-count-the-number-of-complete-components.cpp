class Solution {
public:
    void bfs(int u, vector<vector<int>> &graph, vector<bool> &visited, int &edgeCount, int &vertexCount)
    {
        queue<int> q;
        q.push(u);
        visited[u]=true;

        while(!q.empty())
        {
            vertexCount++;
            int node=q.front();
            q.pop();

            for(auto v: graph[node])
            {
                edgeCount++;
                if(!visited[v])
                {
                    q.push(v);
                    visited[v]=true;
                }
            }
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
                bfs(i, graph, visited, edgeCount, vertexCount);
                cout<<i<<" "<<vertexCount<<" "<<edgeCount<<endl;
                if(edgeCount == (vertexCount*(vertexCount-1)))
                    ans++;
            }
        }

        return ans;
    }
};