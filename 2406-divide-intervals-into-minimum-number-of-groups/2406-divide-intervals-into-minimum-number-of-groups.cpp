class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        int inter=1, ans=1;

        for(int i=1; i<n; i++)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];
            while(!pq.empty() && pq.top()<start)
            {
                pq.pop();
                inter--;
            }

            inter=pq.size()+1;
            ans=max(ans, inter);
            pq.push(end);
            // cout<<inter<<endl;
        }

        return ans;
    }
};