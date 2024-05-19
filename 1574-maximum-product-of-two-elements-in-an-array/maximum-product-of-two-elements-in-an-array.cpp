class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN, smaxi=INT_MIN;
        for(auto i: nums)
        {
            if(i>maxi)
            {
                smaxi=maxi;
                maxi=i;
            }
            else if(i>smaxi)
                smaxi=i;
        }

        return (maxi-1)*(smaxi-1);
    }
};