class Solution {
public:
    bool dfs(int u, int par, vector<vector<int>>& graph, vector<bool>& visited)
    {
        visited[u]=true;
        for(auto v: graph[u])
        {
            if(!visited[v])
            {
                if(dfs(v, u, graph, visited)==false)
                    return false;;
            }
            else if(v!=par)
                return false;
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
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
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                if(count!=0)
                    return false;
                count++;
                if(!dfs(i, -1, graph, visited))
                    return false;
            }

        }

        return true;
    }
};