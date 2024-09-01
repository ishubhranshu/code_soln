class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int totalele=original.size();
        if(totalele != n*m)
            return {};

        vector<vector<int>> ans(m, vector<int>(n));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans[i][j]=original[n*i+j];
            }
        }

        return ans;
    }
};