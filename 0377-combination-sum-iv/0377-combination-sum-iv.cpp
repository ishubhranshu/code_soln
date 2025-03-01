class Solution {
public:
    vector<vector<int>> dp;
    int solve(int ind, int k, vector<int>& current, vector<int>& nums)
    {
        if(k==0)
        {
            return 1;
        }

        if(k<0 || ind==nums.size())
            return 0;

        if(dp[ind][k]!=-1)
            return dp[ind][k];

        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            current.push_back(nums[i]);
            ans+=solve(i, k-nums[i], current, nums);
            current.pop_back();
        }

        return dp[ind][k]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(nums.size(), vector<int>(target+1, -1));
        vector<int> current;
        return solve(0, target, current, nums);
        // return ans;
    }
};