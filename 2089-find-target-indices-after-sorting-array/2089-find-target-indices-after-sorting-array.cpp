class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count=0, less=0;
        for(auto i: nums)
        {
            if(i==target)
                count++;
            else if(i<target)
                less++;
        }

        vector<int> ans(count);
        for(int i=0; i<count; i++)
            ans[i]=less++;

        return ans;
    }
};