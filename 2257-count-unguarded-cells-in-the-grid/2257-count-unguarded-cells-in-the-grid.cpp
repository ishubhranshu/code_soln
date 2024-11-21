class Solution {
public:
    int ans;
    void solve(int r, int c, vector<vector<char>>& grid)
    {
        int n=grid.size(), m=grid[0].size();

        for(int i=r, j=c; i<n; i++)
        {
            if(grid[i][j]=='w' || grid[i][j]=='g')
                break;
            grid[i][j]='*';
            
        }
        for(int i=r, j=c; i>=0; i--)
        {
            if(grid[i][j]=='w' || grid[i][j]=='g')
                break;
            grid[i][j]='*';
        }
        for(int j=c, i=r; j<m; j++)
        {
            if(grid[i][j]=='w' || grid[i][j]=='g')
                break;
            grid[i][j]='*';
        }
        for(int j=c, i=r; j>=0; j--)
        {
            if(grid[i][j]=='w' || grid[i][j]=='g')
                break;
            grid[i][j]='*';
            
        }
    }
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        ans=0;
        vector<vector<char>> grid(n, vector<char>(m, '.'));
        for(auto i: guards)
            grid[i[0]][i[1]]='g';
        for(auto i: walls)
            grid[i[0]][i[1]]='w';

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]=='g')
                {
                    grid[i][j]='*';
                    solve(i, j, grid);
                }
    
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j]=='.')
                    ans++;
    
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //         cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }
        return ans;
        
    }
};