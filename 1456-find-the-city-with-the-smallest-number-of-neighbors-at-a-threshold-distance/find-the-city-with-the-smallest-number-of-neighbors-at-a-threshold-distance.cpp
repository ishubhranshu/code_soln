class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));

        for(auto i: edges)
        {
            adj[i[0]][i[1]]=i[2];
            adj[i[1]][i[0]]=i[2];
        }

        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                {
                    if(i==j)
                        adj[i][j]=0;
                    else if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX && adj[i][j]>adj[i][k]+adj[k][j])
                        adj[i][j]=adj[i][k]+adj[k][j];
                }
        
        vector<int> a(n, 0);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<adj[i][j]<<" ";
                if(i!=j && adj[i][j]<=d)
                    a[i]++;
            }
            cout<<endl;
        }
        int ans=0;
        int neighs=INT_MAX;
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
            if(a[i]<=neighs)
            {
                ans=i;
                neighs=a[i];
            }
        }
        return ans;
    }
};