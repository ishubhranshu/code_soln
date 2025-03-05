class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n=grid.size();
        long long ans=0;

        for(int row=0; row<n; row++)
        {
            int maxEles=limits[row];
            int m=grid[row].size();
            sort(grid[row].begin(), grid[row].end(), greater<int>());

            for(int i=0; i<min(m, maxEles); i++)
            {
                pq.push(grid[row][i]);
                if(pq.size()>k)
                    pq.pop();

            }

        }

        while(k--)
        {
            ans+=pq.top();
            pq.pop();
        }

        return ans;
    }
};