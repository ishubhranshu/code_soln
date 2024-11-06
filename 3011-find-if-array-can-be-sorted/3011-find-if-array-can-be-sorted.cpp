class Solution {
public:
    int csbits(int a)
    {
        int ans=0;
        while(a)
        {
            if(a&1)
                ans++;
            a=a>>1;
        }
        return ans;
    }
    bool canSortArray(vector<int>& nums) {
        int prev_max=-1, prev_min=-1;
        int curr_max=nums[0], curr_min=nums[0];
        int currsetbits=csbits(nums[0]);
        int i=1;
        while(i<nums.size())
        {
            while(i<nums.size() && csbits(nums[i])==currsetbits)
            {
                curr_max=max(curr_max, nums[i]);
                curr_min=min(curr_min, nums[i]);
                i++;
            }
            if((prev_max!=-1 && prev_max>curr_min) || (prev_max==-1 && i!=nums.size() && curr_max>nums[i]) || (i!=nums.size() && curr_max>nums[i]))
                return 0;
            prev_max=curr_max;
            prev_min=curr_min;
            if(nums.size()==i)
                break;
            curr_max=nums[i];
            curr_min=nums[i];
            currsetbits=csbits(nums[i]);
            i++;
        }

        return 1;
        
    }
};