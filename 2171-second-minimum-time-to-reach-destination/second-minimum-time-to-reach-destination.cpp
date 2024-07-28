class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> f(n+1, INT_MAX), s(n+1, INT_MAX);
        f[1]=0;

        queue<pair<int, int>> q;
        q.push({1, 0});

        while(!q.empty())
        {
            int cnode=q.front().first;
            int ctime=q.front().second;
            q.pop();

            for(auto neigh: adj[cnode])
            {
                int ntime=time+ctime;
                if((ctime/change)%2==1)
                    ntime+=change-(ctime%change);

                if(ntime<f[neigh])
                {
                    s[neigh]=f[neigh];
                    f[neigh]=ntime;
                    
                q.push({neigh, ntime});
                }
                else if(ntime<s[neigh] && ntime>f[neigh])
                {
                    s[neigh]=ntime;
                    
                q.push({neigh, ntime});
                }
                if(s[n]!=INT_MAX)
                    return s[n];
            }
            // cout<<s.back()<<endl;
        }

        return -1;
    }
};