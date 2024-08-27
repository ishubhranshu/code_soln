class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int left=0, right=0;
        int ans=INT_MIN, csum=0;

        for(int i=0; i<n; i++)
        {
            csum+=nums[i];
            csum=max(csum, nums[i]); 
            ans=max(ans, csum);
        }

        return ans;
    }
};