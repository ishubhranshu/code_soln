class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> dp(1001, 0);
        for(auto i: trips)
        {
            dp[i[1]]+=i[0];
            dp[i[2]]-=i[0];
        }

        int curr_pass=0;
        for(auto i: dp)
        {
            curr_pass+=i;
            if(curr_pass>capacity)
                return 0;
        }

        return 1;
    }
};