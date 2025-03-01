class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int n=intervals.size();
        pq.push(intervals[0][1]);
        int START=0;
        int END=1;
        for(int i=1; i<n; i++)
        {
            if(intervals[i][START] <= pq.top())
                pq.push(intervals[i][END]);
            else
            {
                pq.pop();
                pq.push(intervals[i][END]);
            }
        }
        return pq.size();
    }
};