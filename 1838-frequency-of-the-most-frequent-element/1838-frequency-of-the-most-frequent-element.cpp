class Solution {
public:
    
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();

        vector<unsigned long long> prefSum(n, 0);
        prefSum[0]=nums[0];
        for(int i=1; i<n; i++)
            prefSum[i]=prefSum[i-1]+nums[i];

        int ans=1;
        for(int i=1; i<n; i++)
        {
            int left=0;
            int right=i;

            while(left<=right)
            {
                long long mid=left+(right-left)/2;

                long long sum=prefSum[i];
                if(mid!=0)
                    sum-=prefSum[mid-1];

                if((i-mid+1)*nums[i] - sum <=k)
                {
                    if(ans<(i-mid+1))
                    ans=i-mid+1;
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
        }
        
        
        return ans;
    }
};