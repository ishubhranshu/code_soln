class Solution {
public:
    vector<int> dp;
    int solve(int ind, string &s, unordered_set<string> &st)
    {
        if(ind==s.length())
            return 0;

        if(dp[ind]!=-1)
            return dp[ind];

        int ans=s.length();
        string cstring="";
        for(int i=ind; i<s.length(); i++)
        {
            int extra=0;
            cstring+=s[i];
            if(st.find(cstring) == st.end())
                extra+=cstring.length();
            extra+=solve(i+1, s, st);
            ans=min(ans, extra);
        }

        return dp[ind] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        dp.resize(s.length(), -1);
        unordered_set<string> st;
        for(auto s: dictionary)
            st.insert(s);
        return solve(0, s, st);
    }
};