class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(isWater[i][j]==1)
                {
                    pq.push({0, {i, j}});
                    isWater[i][j]=0;
                    vis[i][j]=1;
                    
                }
            }
        }

        int dir[]={0,1,0,-1,0};
        while(!pq.empty())
        {
            int cheight=pq.top().first;
            int cx=pq.top().second.first;
            int cy=pq.top().second.second;
            pq.pop();

            for(int i=0; i<4; i++)
            {
                int nx=cx+dir[i];
                int ny=cy+dir[i+1];
                int nheight=cheight+1;

                if(nx<0 || ny<0 || nx==n || ny==m || vis[nx][ny])
                    continue;

                isWater[nx][ny]=nheight;
                pq.push({nheight, {nx, ny}});
                vis[nx][ny]=1;
            }
        }


        return isWater;
    }
};