class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int count=1, rcount=1;
        int maxe = nums[0];

        for(int i=1; i<n; i++)
        {
            if(nums[i]==nums[i-1] && nums[i]==maxe)
            {
                rcount++;
                count = max(count, rcount);
            }
            else
            {
                if(nums[i]>maxe)
                {
                    count=1;
                    maxe=nums[i];
                }
                rcount=1;
            }
        }
        return count;
    }
};