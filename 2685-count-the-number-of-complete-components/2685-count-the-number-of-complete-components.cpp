class Solution {
public:
    class DisjointSet{
        vector<int> par;

        public:
        vector<int> size;
            DisjointSet(int n)
            {
                par.resize(n);
                size.resize(n, 1);
                for(int i=0; i<n; i++)
                    par[i]=i;
            }
            int getPar(int x)
            {
                if(par[x]==x)
                    return x;

                return par[x]=getPar(par[x]);
            }

            void merge(int x, int y)
            {
                int px=getPar(x);
                int py=getPar(y);

                if(px==py)
                    return;
                if(size[px] > size[py])
                {
                    size[px]+=size[py];
                    par[py]=px;
                }
                else
                {
                    size[py]+=size[px];
                    par[px]=py;
                }
            }    
    };

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        unordered_map<int, int> edgeCount;
        
        for(auto &edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            
            ds.merge(u, v);
        }

        for(auto &edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            
            edgeCount[ds.getPar(u)]++;
        }
        int ans=0;
        for(auto entry: edgeCount)
        {
            int node=entry.first;
            int edges=entry.second;
            int vertex=ds.size[node];
            cout<<node<<" "<<edges<<" "<<vertex<<endl;
            if(edges == ((vertex)*(vertex-1))/2)
                ans++;
        }
        for(int i=0; i<n; i++)
            if(ds.getPar(i)==i && ds.size[i]==1)
                ans++;

        return ans;
        
    }
};