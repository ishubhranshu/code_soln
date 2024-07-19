class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mt) {
        int n=mt.size(), m=mt[0].size();
        int ans=INT_MIN;
        vector<int> cols(m, INT_MIN), rows(n, INT_MAX);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cols[j]=max(cols[j], mt[i][j]);
                rows[i]=min(rows[i], mt[i][j]);
            }
            ans=max(ans, rows[i]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(rows[i]==mt[i][j] && cols[j]==mt[i][j])
                    return {mt[i][j]};
            }
        }
        return {};
    }
};