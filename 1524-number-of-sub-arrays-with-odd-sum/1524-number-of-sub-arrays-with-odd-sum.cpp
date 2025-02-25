class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount=0, evenCount=1;
        long long cumSum=0;
        long long ans=0;
        int MOD=1e9+7;
        for(auto num: arr)
        {
            cumSum=cumSum+num;

            if(cumSum%2)
            {
                ans=(ans+evenCount)%MOD;
                oddCount++;
            }
            else
            {
                ans=(ans+oddCount)%MOD;
                evenCount++;
            }
        }
        return ans;
    }
};