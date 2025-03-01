class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals;
        int START=0;
        int END=1;
        int i=0;
        int n=intervals.size();
        while(i<n)
        {
            if(intervals[i][END]<newInterval[START])
                newIntervals.push_back(intervals[i]);

            else if(intervals[i][START]>newInterval[END])
                break;
            else
            {
                newInterval[START]=min(newInterval[START], intervals[i][START]);
                newInterval[END]=max(newInterval[END], intervals[i][END]);
            }
            i++;
        }
        newIntervals.push_back(newInterval);
        while(i<n)
            newIntervals.push_back(intervals[i++]);

        return newIntervals;
    }
};