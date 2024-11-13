class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), ans=0;
        // int l=0, r=n-1;

        for(int i=0; i<n; i++)
        {
            int lb=lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i])-begin(nums);
            int l=lb-1-i;

            int ub=upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i])-begin(nums);
            int u=ub-1-i;

            // cout<<u<<" "<<l<<endl;
            ans+=(u-l);
        }

        return ans;
    }
};