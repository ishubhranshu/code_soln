class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        dist[0][0]=0;

        while(!pq.empty())
        {
            int cd=pq.top().first;
            int cx=pq.top().second.first;
            int cy=pq.top().second.second;
            pq.pop();
            
            int  pdir[][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

            for(int i=0; i<4; i++)
            {
                int nx=cx+pdir[i][0];
                int ny=cy+pdir[i][1];
                if(nx<0 || ny<0 || nx==n || ny==m)
                    continue;

                int nd=cd;
                if(i != grid[cx][cy]-1)
                    nd++;

                if(nd<dist[nx][ny])
                {
                    dist[nx][ny]=nd;    
                    pq.push({nd, {nx, ny}});
                }
            }
        }

        return dist[n-1][m-1];
    }
};