class Solution {
public:
    int cti(char c)
    {
        return c-'a';
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        int N=26, n=original.size();
        
        long long ans=0;
        vector<vector<long>> adj(N, vector<long>(N, INT_MAX));
        for(int i=0; i<n; i++)
        {
            int s=cti(original[i]);
            int d=cti(changed[i]);
            if(adj[s][d]>(long long)cost[i])
                adj[s][d]=(long long)cost[i];
        }
        for(int k=0; k<N; k++)
        {
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    if(i==j)
                        adj[i][j]=0;
                    else
                    {
                        if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX)
                            if(adj[i][j]>adj[i][k]+adj[k][j])
                                adj[i][j]=adj[i][k]+adj[k][j];
                    }
                }
            }
        }

        for(auto i: adj)
        {
            for(auto j: i)
            {
                if(j==INT_MAX)
                    cout<<-1<<"\t";
                else
                    cout<<j<<"\t";
            }
            cout<<endl;
        }
        for(int i=0; i<source.length(); i++)
        {
            if(source[i]==target[i])
                continue;
            if(adj[cti(source[i])][cti(target[i])]==INT_MAX)
                return -1;
            ans+=adj[cti(source[i])][cti(target[i])];
        }

        return ans;
    }
};