class Solution {
public:
    int count(int ind, vector<int>& nums, int oor, int &moor)
    {
        if(ind==nums.size())
        {
            if(oor==moor)
                return 1;
            return 0;
        }

        int ans=0;
        ans+=count(ind+1, nums, oor|nums[ind], moor);
        ans+=count(ind+1, nums, oor, moor);

        return ans;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int moor=0;
        for(auto i: nums)
            moor|=i;

        return count(0, nums, 0, moor);
        
    }
};