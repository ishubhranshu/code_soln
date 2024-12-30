class Solution {
public:
    vector<int> dp; 
    int MOD=1e9+7;
    int solve(int length, int &low, int &high, int &zero, int &one)
    {
        if(length>high)
            return 0;
        
        if(dp[length]!=-1)
            return dp[length];

        int count=0;
        if(length>=low)
            count++;

        count+=solve(length+zero, low, high, zero, one);
        count+=solve(length+one, low, high, zero, one);

        return dp[length]=(count)%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        dp.resize(high+1, -1);
        return solve(0, low, high, zero, one);
    }
};