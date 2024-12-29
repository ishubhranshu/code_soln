class Solution {
public:
    int MOD=1e9+7;
    vector<vector<int>> dp;
    int solve(int ind1, int ind2, vector<string>& words, string &target)
    {
        if(ind2==target.length())
            return 1;
        
        if(ind1==words[0].size())
            return 0;

        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        long long take=0;
        for(auto word: words)
            if(word[ind1]==target[ind2])
                take++;

        take=(take*(solve(ind1+1, ind2+1, words, target))%MOD)%MOD;
        
        long long ntake=solve(ind1+1, ind2, words, target)%MOD;

        return dp[ind1][ind2]=(take+ntake)%MOD;
    }
    int numWays(vector<string>& words, string target) {
        dp.resize(words[0].size(), vector<int>(target.length(), -1));
        return solve(0, 0, words, target);
    }
};