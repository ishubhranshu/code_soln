class Solution {
public:
    vector<int> cans;
    int solve(int ind, int sum, vector<int>& nums)
    {
        if(sum==0)
        {
            // for(auto i: cans)
            //     cout<<i<<" ";
            // cout<<endl;
            return 1;
        }

        if(ind==nums.size() || sum<0)
            return 0;

        int ans=0;
        for(int i=ind; i<nums.size(); i++)
        {
            cans.push_back(nums[i]);
            ans+=solve(0, sum-nums[i], nums);
            cans.pop_back();
        }

        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        return solve(0, target, nums);
    }
};