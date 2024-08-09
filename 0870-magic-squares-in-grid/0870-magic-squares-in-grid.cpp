class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& grid)
    {
        unordered_set<int> st;
        for(int r = 0; r < 3; r++) {
            for(int c = 0; c < 3; c++) {
                int num = grid[i + r][j + c];
                if(num > 9 || num < 1 || st.find(num) != st.end())
                    return false;
                st.insert(num);
            }
        }

        int d1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        int d2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];

        if(d1!=d2)
            return 0;

        for(int r=0; r<3; r++)
        {
            if(grid[i+r][j]+grid[i+r][j+1]+grid[i+r][j+2]!=d1)
                return 0;
            if(grid[i][j+r]+grid[i+1][j+r]+grid[i+2][j+r]!=d1)
                return 0;
        }

        return 1;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=0;
        for(int i=0; i<n-2; i++)
            for(int j=0; j<m-2; j++)
                if(check(i, j, grid))
                    ans++;

        return ans;
    }
};