class Solution {
public:
    int dfs(int x, int y, vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(x<0 || y<0 || x==n || y==m || grid[x][y]<=0)
            return 0;

        int temp=grid[x][y];
        grid[x][y]=-1;
        int ans=0;

        int dirs[]={0,1,0,-1,0};
        for(int dir=0; dir<4; dir++)
        {
            int nx=x+dirs[dir];
            int ny=y+dirs[dir+1];

            ans=max(ans, temp+dfs(nx, ny, grid));
        }
        grid[x][y]=temp;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                ans=max(ans, dfs(i, j, grid));

        return ans;
        
    }
};