class Solution {
public:
    void traverse(int r, int c, vector<vector<int>>& grid1,
                    vector<vector<int>>& grid2,
                    vector<vector<int>>& vis, int &count)
    {
        int n=grid1.size(), m=grid1[0].size();
        if(r<0 || c<0 || r==n || c==m || grid2[r][c]==0 || vis[r][c]==1)
            return;
        
        vis[r][c]=1;
        if(grid2[r][c]==1 && grid1[r][c]!=1)
            count=0;

        int dir[]={0,1,0,-1,0};
        for(int i=0; i<4; i++)
        {
            int nr=r+dir[i];
            int nc=c+dir[i+1];
            traverse(nr, nc, grid1, grid2, vis, count);
        }

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(), m=grid1[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans=0;
        for(int r=0; r<n; r++)
        {
            for(int c=0; c<m; c++)
            {
                if(vis[r][c]==0 && grid2[r][c]==1)
                {
                    int count=1;
                    traverse(r, c, grid1, grid2, vis, count);
                    cout<<r<<" "<<c<<" "<<count<<endl;
                    ans+=count;
                }
            }
        }
        return ans;
    }
};