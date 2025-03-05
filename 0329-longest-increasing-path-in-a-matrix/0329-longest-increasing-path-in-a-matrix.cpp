class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& lPath)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        if(lPath[x][y]!=-1)
            return lPath[x][y];
        
        int dirs[]={0,1,0,-1,0};

        int lP=1;
        for(int d=0; d<4; d++)
        {
            int nx=x+dirs[d];
            int ny=y+dirs[d+1];

            if(nx<0 || ny<0 || nx==n || ny==m || matrix[nx][ny]<=matrix[x][y])
                continue;
            
            lP=max(lP, 1+solve(nx, ny, matrix, lPath));
        }
        
        return lPath[x][y]=lP;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> lPath(n, vector<int>(m, -1));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(lPath[i][j]==-1)
                    solve(i, j, matrix, lPath);
            }
        }

        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans=max(ans, lPath[i][j]);
                // cout<<lPath[i][j]<<" ";
            }
            // cout<<endl;
        }

        return ans;
    }
};