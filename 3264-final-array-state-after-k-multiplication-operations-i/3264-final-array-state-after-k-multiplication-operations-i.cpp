class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int n=nums.size();
        for(int i=0; i<n; i++)
            pq.push({nums[i], i});

        while(k--)
        {
            int ele = pq.top().first;
            int pos = pq.top().second;
            pq.pop();

            pq.push({ele*multiplier, pos});
        }

        while(!pq.empty())
        {
            nums[pq.top().second]=pq.top().first;
            pq.pop();
        }

        return nums;
    }
};