class Solution {
public:
    int solve(int ind, vector<int>& nums, int k, unordered_map<int, int> &ump)
    {
        int n=nums.size();
        if(ind==n)
            return ump.size()>0;

        int ans=0;
        if(ump[nums[ind]+k] == 0 && ump[nums[ind]-k] == 0)
        {
            ump[nums[ind]]++;
            ans+=solve(ind+1, nums, k, ump);
            ump[nums[ind]]--;
            if(ump[nums[ind]]==0)
                ump.erase(nums[ind]);
        }
        ans+=solve(ind+1, nums, k, ump);

        return ans;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        return solve(0, nums, k, ump)-1;
    }
};