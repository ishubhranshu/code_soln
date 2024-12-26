class Solution {
public:
    int range=0;
    int solve(int ind, vector<int>& nums, int target, int sum, vector<vector<int>> dp)
    {
        if(ind==nums.size())
        {
            if(sum==target)
                return 1;
            return 0;
        }
        // cout<<sum<<" "<<range<<" "<<sum+target<<endl;

        if(dp[ind][sum+range]!=-1)
            return dp[ind][sum+range];

        int total=0;
            
        return dp[ind][sum+range]=solve(ind+1, nums, target, sum+nums[ind], dp)+solve(ind+1, nums, target, sum-nums[ind], dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        for(auto i: nums)
            range+=i;

        vector<vector<int>> dp(n, vector<int>(2*range+1, -1));
        return solve(0, nums, target, 0, dp);
    }
};