class Solution {
public:
    int solve(int ind, vector<int>& nums, int target, int sum, unordered_map<string, int> &ump)
    {
        if(ind==nums.size())
        {
            if(sum==target)
                return 1;
            return 0;
        }

        if(ump.find(to_string(ind)+"-"+to_string(sum))!=ump.end())
            return ump[to_string(ind)+"-"+to_string(sum)];

        return ump[to_string(ind)+"-"+to_string(sum)]=solve(ind+1, nums, target, sum+nums[ind], ump)+solve(ind+1, nums, target, sum-nums[ind], ump);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> ump;
        return solve(0, nums, target, 0, ump);
    }
};