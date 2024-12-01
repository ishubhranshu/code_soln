class Solution {
public:

        
        
        vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<int> trav;
        unordered_map<int, vector<int>> graph;
        int n=pairs.size();
        
        for(auto p: pairs)
            graph[p[0]].push_back(p[1]);

        unordered_map<int, int> deg;
        for(auto node: graph)
        {
            deg[node.first]-=node.second.size();
            for(auto neigh: node.second)
                deg[neigh]++;
        }
        
        int start=pairs[0][0];
        for(auto d: deg)
        {
            if(d.second<0)
            {
                start=d.first;
                break;
            }
        }
        vector<vector<int>> ans;
        stack<int> stk;
        stk.push(start);


        while(!stk.empty())
        {
            int node=stk.top();
            if(graph[node].size())
            {
                int next=graph[node].back();
                graph[node].pop_back();
                stk.push(next);
            }
            else
            {
                trav.push_back(node);
                stk.pop();
            }
        }
        reverse(trav.begin(), trav.end());
        
        for(int i=0; i<trav.size()-1; i++)
            ans.push_back({trav[i], trav[i+1]});

        return ans;
    }
};