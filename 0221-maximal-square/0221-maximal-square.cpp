class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans=0;
        for(int i=0; i<n; i++)
            if(matrix[i][0]=='1')
            {
                dp[i][0]=1;
                ans=1;
            }
        for(int j=0; j<m; j++)
            if(matrix[0][j]=='1')
            {
                dp[0][j]=1;
                ans=1;
            }
          
        
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(matrix[i][j]=='1')
                {
                    if(matrix[i-1][j]=='1' && matrix[i-1][j-1]=='1' && matrix[i][j-1]=='1' )
                        dp[i][j]=1+min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                    else
                        dp[i][j]=1;
                    ans=max(ans, dp[i][j]);
                }
                
            }
        }

        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         cout<<dp[i][j]<<" ";    
        //     }
        //     cout<<endl;
        // }

        return ans*ans;
    }
};