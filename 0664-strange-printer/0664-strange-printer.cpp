class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l, int r, string &s)
    {
        if(l==r)
            return 1;

        if(dp[l][r]!=-1)
            return dp[l][r];
        int ans=INT_MAX;
        for(int i=l; i<r; i++)
        {
            int left=solve(l, i, s);
            int right=solve(i+1, r, s);

            if(s[l]==s[i+1])
                ans=min(ans, left+right-1);
            else
                ans=min(ans, left+right);
        }
        return dp[l][r]=ans;
    }
    int strangePrinter(string s) {
        string ss=s;
        int n=s.length();
        dp.resize(n, vector<int>(n, -1));
        return solve(0, n-1, ss);
    }
};