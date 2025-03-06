class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int first=0; first<n; first++)
        {
            for(int second=0; second<n; second++)
            {
                if(first==second)
                    continue;
                if(nums[first]+nums[second]==target)
                    return {first, second};
            }
        }

        return {-1,-1};
    }
};