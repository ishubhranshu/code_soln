class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int> &color)
    {
        queue<int> q;
        color[node]=0;
        q.push(node);
        
        while(!q.empty())
        {
            int node=q.front();
            int currClr=color[node];
            q.pop();

            for(auto neigh: graph[node])
            {
                if(color[neigh]==-1)
                {
                    color[neigh]=1-currClr;
                    q.push(neigh);
                }
                else if(color[neigh]==currClr)
                    return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n, -1);
        
        for(int i=0; i<n; i++)
            if(color[i]==-1 && !bfs(i, graph, color))
                return false;

        return true;

    }
};