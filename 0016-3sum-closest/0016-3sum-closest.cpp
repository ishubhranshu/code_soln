class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=INT_MAX, n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            int j=i+1, k=n-1;

            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];

                // ans=min(abs(target-ans), abs(sum-target));
                if(abs(target-sum)<abs(target-ans))
                    ans=sum;

                if(sum<target)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};