class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0;
        int mask=0;
        int n=nums.size();
        int ans=1;
        for(int right=0; right<n; right++)
        {
            while(mask & nums[right])
            {
                mask=mask & (~nums[left]);
                left++;
            }
            mask=mask | nums[right];
            ans=max(ans, right-left+1);
        }

        return ans;
    }
};