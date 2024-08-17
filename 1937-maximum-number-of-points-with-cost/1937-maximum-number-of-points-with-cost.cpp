class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size(), m=points[0].size();
        long long int dp[n][m];
        // vector<vector< long>> dp(n, vector<int>(m));
        for(int j=0; j<m; j++)
            dp[0][j]=points[0][j];

        for(int row=1; row<n; row++)
        {
            long long int left[m], right[m];
            // vector< long> left(m), right(m);
            left[0]=dp[row-1][0]+points[row][0];
            right[m-1]=dp[row-1][m-1]+points[row][m-1];

            for(int j=1; j<m; j++)
                left[j]=points[row][j]+max(left[j-1]-1-points[row][j-1], dp[row-1][j]);

            for(int j=m-2; j>=0; j--)
                right[j]= points[row][j]+max(right[j+1]-1-points[row][j+1], dp[row-1][j]);
        
            for(int j=0; j<m; j++)
                dp[row][j]=max(left[j], right[j]);
        
            // for(auto i: left)
            //     cout<<i<<" ";
            // cout<<endl;
            // for(auto i: right)
            //     cout<<i<<" ";
            // cout<<endl;
            // cout<<endl;

            // for(auto i: dp)
            // {
            //     for(auto j: i)
            //         cout<<j<<" ";
            //     cout<<endl;
            // }
            // cout<<endl;
        }

        long long int ans=INT_MIN;
        for(auto i:dp[n-1])
            if(i>ans)
                ans=i;

        return ans;
    }   
};