class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(auto i: nums)
            ump[i]++;

        priority_queue<pair<int, int>> pq;
        for(auto i: ump)
            pq.push({i.second, i.first});

        vector<int> ans;
        while(k-- && pq.size())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};