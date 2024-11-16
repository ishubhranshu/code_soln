class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1)
            return nums;
        
        vector<int> ans;
        int l=0, r=1;
        int count=(nums[r]==nums[l]+1)+1;
        for(r=1; r<k; r++)
        {
            if(nums[r]==nums[r-1]+1)
                count++;
            else
                count=1;
        }
        cout<<r<<" "<<count<<endl;

        if(k<=count)
            ans.push_back(nums[k-1]);
        else
            ans.push_back(-1);

        r=k;
        while(r<nums.size())
        {
            if(nums[r]==nums[r-1]+1)
                count++;
            else
                count=1;
            
            if(k<=count)
                ans.push_back(nums[r]);
            else
                ans.push_back(-1);
            r++;
            l++;
        }

        return ans;
    }
};