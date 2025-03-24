class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans=0;

        int start=meetings[0][0];
        int end=meetings[0][1];
        ans+=(start-1);

        for(auto meet: meetings)
        {
            // cout<<ans<<" ";
            int cStart=meet[0];
            int cEnd=meet[1];
            
            if(cStart>end)
                ans+=(cStart-end-1);

            start=cStart;
            end=max(end, cEnd);
        }
        // cout<<ans<<" ";
        ans+=(max(0, days-end));
        // cout<<ans<<" ";

        return ans;

    }
};