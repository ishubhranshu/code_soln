class Solution {
public:
    bool solve(int ind, vector<int>& nums, int k , int csum, int &rsum, vector<int> &used)
    {
        if(k==0)
            return 1;
        if(csum==rsum)
            return solve(0, nums, k-1, 0, rsum, used);

        for(int i=ind; i<nums.size(); i++)
        {
            if(csum+nums[i]>rsum || used[i])
                continue;
            used[i]=1;
            if(solve(i+1, nums, k, csum+nums[i], rsum, used))
                return 1;
            used[i]=0;
        }
        return 0;
    }
    bool makesquare(vector<int>& nums) {
        int sum=0, k=4;
        for(auto i: nums)
            sum+=i;
        if(sum%k || nums.size()<k)
            return 0;
        sum/=k;
        vector<int> used(nums.size(), 0);
        return solve(0, nums, k, 0, sum, used);
    }
};