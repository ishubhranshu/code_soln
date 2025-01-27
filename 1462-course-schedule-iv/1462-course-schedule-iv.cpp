class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, int &dest)
    {
        vis[node]=1;
        for(auto neigh: graph[node])
        {
            if(neigh==dest)
                return 1;
            if(!vis[neigh])
                if(dfs(neigh, graph, vis, dest))
                    return 1;
        }
        return 0;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        for(auto p: prerequisites)
        {
            graph[p[0]].push_back(p[1]);
        }

        vector<bool> ans;

        for(auto q: queries)
        {
            vector<bool> vis(numCourses, 0);
            ans.push_back(dfs(q[0], graph, vis, q[1]));
        }

        return ans;
    }
};