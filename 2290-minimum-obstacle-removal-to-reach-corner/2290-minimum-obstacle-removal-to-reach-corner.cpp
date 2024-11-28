class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0]=0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {0, 0}});

        while(!q.empty())
        {
            int d=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            q.pop();

            int dirs[]={0,1,0,-1,0};

            for(int i=0; i<4; i++)
            {
                int nr=r+dirs[i];
                int nc=c+dirs[i+1];

                if(nr<0 || nc<0 || nr>=n || nc>=m || dist[nr][nc]<=d+grid[nr][nc])
                    continue;

                dist[nr][nc]=d+grid[nr][nc];
                q.push({dist[nr][nc], {nr, nc}});
            }
        }

        return dist[n-1][m-1];
    }
};