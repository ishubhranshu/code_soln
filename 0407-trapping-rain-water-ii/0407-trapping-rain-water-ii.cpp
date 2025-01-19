class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size(), m=heightMap[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    pq.push({heightMap[i][j], {i, j}});
                    // cout<<i<<" "<<j<<" "<<pq.size()<<endl;
                    vis[i][j]=1;
                }
            }
        }

        while(!pq.empty())
        {
            int cheight=pq.top().first;
            int ci=pq.top().second.first;
            int cj=pq.top().second.second;
            pq.pop();

            int pdir[]={0,1,0,-1,0};

            for(int i=0; i<4; i++)
            {
                int ni=ci+pdir[i];
                int nj=cj+pdir[i+1];

                if(ni<0 || nj<0 || ni==n || nj==m || vis[ni][nj])
                    continue;

                // cout<<ci<<" "<<cj<<" ==> "<<ni<<" "<<nj<<endl;
                // cout<<cheight<<endl;
                ans+=max(0, heightMap[ci][cj]-heightMap[ni][nj]);
                heightMap[ni][nj]=max(heightMap[ci][cj], heightMap[ni][nj]);
                pq.push({heightMap[ni][nj], {ni, nj}});
                vis[ni][nj]=1;
            }
        }

        return ans;
    }
};