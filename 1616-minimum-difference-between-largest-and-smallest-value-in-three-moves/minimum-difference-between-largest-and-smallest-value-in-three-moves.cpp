class Solution {
public:
    
    int minDifference(vector<int>& nums) {

        int n = nums.size();
        if(n<5)
            return 0;
        sort(nums.begin(), nums.end());
        if(nums[0] == nums[n-1])
            return 0;
        
        int diff = INT_MAX;
        for(int i=0; i<4; i++)
            diff=min(diff, nums[n-1-3+i]-nums[i]);
        
        return diff;
    }
};