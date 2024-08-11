class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid,  set<vector<int>> &st)
    {
        int n=grid.size(), m=grid[0].size();
        if(r<0 || c<0 || r==n || c==m || grid[r][c]!=1)
            return;

        grid[r][c]=-1;
        st.insert({r, c});
        int dr[] = {0, 1, 0, -1}; 
        int dc[] = {1, 0, -1, 0}; 
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i]; 
            int nc = c + dc[i]; 
            dfs(nr, nc, grid, st);
        }

    }

    int minDays(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        set<vector<int>> st;
        vector<vector<int>> temp = grid;
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(temp[i][j]==1)
                {
                    // cout<<i<<" "<<j<<" "<<temp[i][j]<<endl;
                    count++;
                    // cout<<i<<" "<<j<<endl;
                    dfs(i, j, temp, st);
                }
            }
        }
        cout<<count<<endl;
        if(count!=1)
            return 0;
            
        for(auto ii: st)
        {
            vector<vector<int>> ttemp = grid;
            ttemp[ii[0]][ii[1]]=0;
            // cout<<ii[0]<<" "<<ii[1]<<endl;
            int ccount=0;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(ttemp[i][j]==1)
                    {
                        ccount++;
                        dfs(i, j, ttemp, st);
                    }
                }
            }
            // cout<<ccount<<endl;
            if(ccount!=1)
                return 1;
        }

        return 2;
    }
};