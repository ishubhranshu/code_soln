class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<int> arr;
        for(int i=0; i<n; i++)
        {
            int sum=nums[i];
            arr.push_back(sum);
            for(int j=i+1; j<n; j++)
            {
                sum+=nums[j];
                arr.push_back(sum);
            }   
        }

        sort(begin(arr), end(arr));

        int ans=0;
        for(int i=l-1; i<r; i++)
            ans=(ans+arr[i])%(int)(1e9+7);

        return ans;
    }
};