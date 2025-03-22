class Solution {
public:
    
    string hash(vector<int> &neighs)
    {
        string s="";
        sort(neighs.begin(), neighs.end());
        for(auto u: neighs)
            s+=(to_string(u)+",");
        
        return s;
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
        for(int i=0; i<n; i++)
            graph[i].push_back(i);

        unordered_map<string, int> edgeFreq;
        for(int i=0; i<n; i++)
            edgeFreq[hash(graph[i])]++;

        int ans=0;
        for(auto entry: edgeFreq)
        {
            int numVertex=((entry.first).length())/2;
            int count=entry.second;
            // cout<<numVertex<<" "<<count<<endl;
            if(numVertex == count)
                ans++;
        }

        return ans;
    }
};