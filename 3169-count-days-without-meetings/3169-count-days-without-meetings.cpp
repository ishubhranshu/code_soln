class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int freeDays=0;
        int lastEnd=1;
        int n=meetings.size();
        freeDays+=(meetings[0][0]-lastEnd);
        lastEnd=meetings[0][1];
        for(int i=1; i<n; i++)
        {
            int meetStart=meetings[i][0];
            int meetEnd=meetings[i][1];

            if(meetStart > lastEnd)
                freeDays+=(meetStart-lastEnd-1);
            lastEnd=max(lastEnd, meetEnd);
        }
        if(lastEnd<days)
            freeDays+=(days-lastEnd);
        return freeDays;
    }
};