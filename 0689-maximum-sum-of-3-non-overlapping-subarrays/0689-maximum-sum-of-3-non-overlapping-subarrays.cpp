class Solution {
public:
    vector<int> ans;
    vector<vector<int>> dp;
    int helper(int ind, vector<int>& subsum, int k, int count)
    {
        if(count==0)
            return 0;
        if(ind>=subsum.size())
            return -1e7;

        if(dp[ind][count]!=-1)
            return dp[ind][count];

        int take=subsum[ind]+helper(ind+k, subsum, k, count-1);
        int ntake=helper(ind+1, subsum, k, count);

        return dp[ind][count]=max(take, ntake);
    }
    void solve(int ind, vector<int>& subsum, int k, int count)
    {
        if(ind>=subsum.size() || count==0)
            return;

        int take=subsum[ind]+helper(ind+k, subsum, k , count-1);
        int ntake=helper(ind+1, subsum, k , count);

        if(take>=ntake)
        {
            ans.push_back(ind);
            solve(ind+k, subsum, k, count-1);
        }
        else
        {
            solve(ind+1, subsum, k, count);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> subsum;
        int i=0, j=0, ssum=0;
        while(j<nums.size())
        {
            if(j-i==k)
            {
                subsum.push_back(ssum);
                ssum-=nums[i];
                i++;
            }
            ssum+=nums[j];
            j++;
        }

        dp.resize(subsum.size(), vector<int>(4, -1));
        solve(0, subsum, k, 3);

        return ans;
    }
};