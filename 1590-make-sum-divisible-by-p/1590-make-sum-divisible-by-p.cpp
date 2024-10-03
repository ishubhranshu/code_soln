class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;

        for(auto i: nums)
            sum+=i;

        sum=sum%p;

        if(sum==0)
            return 0;

        long long n=nums.size();
        long long csum=0, ans=n;
        unordered_map<long long, long long> ump;
        ump[0]=-1;
        for(int i=0; i<n; i++) 
        {
            csum=(csum+nums[i])%p;
            if(ump.find((csum-sum+p)%p) != ump.end())
                ans=min(ans, i-ump[(csum-sum+p)%p]);
            ump[(csum)]=i;
        }

        return ans==n ? -1 : ans;
    }
};