class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int opCount=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0 && i+2<n)
            {
                opCount++;
                for(int j=i; j<i+3; j++)
                    nums[j]^=1;
            }
        }

        return nums[n-1] && nums[n-2] ? opCount : -1;
    }
};