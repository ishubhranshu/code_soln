class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        int n=points.size();
        for(int i=0; i<n; i++)
        {
            double x=points[i][0];
            double y=points[i][1];
            x*=x;
            y*=y;
            x=sqrt(x+y);
            pq.push({x, i});
        }
        vector<vector<int>> ans;
        while(k--)
        {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};