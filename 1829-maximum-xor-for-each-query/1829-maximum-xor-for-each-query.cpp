class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int total=0;
        for(auto i: nums)
            total=total^i;

        int n=nums.size();
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--)
        {
            int ttotal=total;
            int tans=0;
            for(int j=0; j<maximumBit; j++)
            {
                if(!(ttotal&1))
                    tans=tans|(1<<j);
                ttotal=ttotal>>1;
            }
            ans[n-1-i]=tans;
            total=total^nums[i];
        }
        return ans;
    }
};