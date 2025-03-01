class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        int lastEnd=-1;
        for(auto interval: intervals)
        {
            int currStart=interval[0];
            int currEnd=interval[1];

            if(currStart > lastEnd)
                merged.push_back(interval);
            else
            {
                merged.back()[0]=min(merged.back()[0], currStart);    
                merged.back()[1]=max(merged.back()[1], currEnd);
            }
            lastEnd=merged.back()[1];
        }
        return merged;
    }
};