class Solution {
public:
    int total=0;
    vector<vector<int>> dp;
    int solve(int left, int right, vector<int>& stoneValue, int t)
    {
        if(right<=left)
            return 0;

        if(dp[left][right]!=-1)
            return dp[left][right];
        int sum=0;
        int ans=0;
        for(int i=left; i<right; i++)
        {
            sum+=stoneValue[i];
            int rem=t-sum;
            // cout<<left<<" "<<i<<" "<<right<<" "<<sum<<" "<<rem<<endl;
            if(sum<rem)
                ans=max(ans, sum+solve(left, i, stoneValue, t-rem));
            else if(sum>rem)
                ans=max(ans, rem+solve(i+1, right, stoneValue, t-sum));
            else
                ans=max(ans, max(sum+solve(left, i, stoneValue, t-rem), rem+solve(i+1, right, stoneValue, t-sum)));
        }

        return dp[left][right]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        for(auto i: stoneValue)
            total+=i;
        int n=stoneValue.size();
        dp.resize(n, vector<int>(n, -1));
        return solve(0, n-1, stoneValue, total);
        
    }
};