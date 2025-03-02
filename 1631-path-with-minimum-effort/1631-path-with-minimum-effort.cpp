class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        efforts[0][0]=0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});

        while(!q.empty())
        {
            int currEff=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();

            int dir[]={0,1,0,-1,0};
            for(int d=0; d<4; d++)
            {
                int nx=x+dir[d];
                int ny=y+dir[d+1];

                if(nx<0 || nx==n || ny<0 || ny==m)
                    continue;

                int newNeighEff=max(currEff, heights[nx][ny]-heights[x][y]);

                if(efforts[nx][ny] > newNeighEff)
                {
                    efforts[nx][ny] = newNeighEff;
                    q.push({efforts[nx][ny], {nx, ny}});
                }
            }
        }

        return efforts.back().back();
    }
};