class Solution {
public:
    vector<int> dp;
    int solve(int ind, vector<int>& nums, int left, int right)
    {
        int n=nums.size();
        if(ind==nums.size())
            return 0;

        if(dp[ind]!=-1)
            return dp[ind];
        int ans=0;
        if(ind!=0 && left>=right)
        {
            // cout<<ind<<" "<<left<<" "<<right<<endl;
            ans++;
        }

        ans+=solve(ind+1, nums, left+nums[ind], right-nums[ind]);

        return dp[ind]=ans;
    }
    int waysToSplitArray(vector<int>& nums) 
    {
        dp.resize(nums.size(), -1);
        int sum=0;
        for(auto num: nums)
            sum+=num;

        return solve(0, nums, 0, sum);

    }
};