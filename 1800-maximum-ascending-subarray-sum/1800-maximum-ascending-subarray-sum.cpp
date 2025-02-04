class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int rsum=0, ans=0;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(i==0 || nums[i]>nums[i-1])
                rsum+=nums[i];
            else
                rsum=nums[i];

            ans=max(ans, rsum);
        }

        return ans;
    }
};