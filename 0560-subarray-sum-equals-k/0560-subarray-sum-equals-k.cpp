class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        ump[0]=1;
        int ans=0;
        int csum=0;
        int n=nums.size();

        for(int i=0; i<n; i++)
        {
            csum+=nums[i];

            if(ump.find(csum-k)!=ump.end())
                ans+=ump[csum-k];

            ump[csum]++;
        }

        return ans;

    }
};