class Solution {
public:
    int solve(int ind, string &s, unordered_set<string> &st, int n, vector<vector<int>> &dp)
    {
        if(ind==s.length())
            return n;

        if(dp[ind][n]!=-1)
            return dp[ind][n];

        int ans=s.length();
        for(auto word: st)
        {
            int len = word.length();
            // cout<<word<<" "<<s.substr(ind, len)<<endl;
            if(s.substr(ind, len) == word)
                ans=min(ans, solve(ind+len, s, st, n-len, dp));
        }
        ans=min(ans, solve(ind+1, s, st, n, dp));
        return dp[ind][n]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        for(auto ss: dictionary)
            st.insert(ss);

        int n=s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans=solve(0, s, st, n, dp);

        for(auto i: dp)
        {
            for(auto j: i)
                cout<<j<<" ";
            cout<<endl;
        }
        return ans;
    }
};