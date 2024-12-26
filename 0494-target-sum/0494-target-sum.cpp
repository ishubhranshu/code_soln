class Solution {
public:

    int solve(int ind, vector<int> &nums, int target)
    {
        if(ind==nums.size())
        {
            if(target==0)
                return 1;
            return 0;
        }

        return solve(ind+1, nums, target-nums[ind])+solve(ind+1, nums, target+nums[ind]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, nums, target);
    }
};