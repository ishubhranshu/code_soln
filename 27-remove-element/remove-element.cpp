class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0; int right=0, n=nums.size();
        
        while(right<n)
        {
            if(nums[right]==val)
                right++;
            else
            {
                nums[left]=nums[right];
                left++;
                right++;
            }
        }

        return left;
    }
};