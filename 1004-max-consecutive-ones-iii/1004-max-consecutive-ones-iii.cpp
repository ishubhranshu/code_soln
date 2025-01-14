class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int  left=0, right=0, zcount=0, len=0;
        for(right=0; right<nums.size(); right++)
        {
            if(nums[right]==0)
                zcount++;
            while(left<=right && zcount>k)
            {
                if(nums[left]==0)
                    zcount--;
                left++;
            }
            len=max(len, right-left+1);
        }
        return len;
    }
};