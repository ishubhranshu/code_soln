class Solution {
public:
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int, int>> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;


        for(int i=0; i<n; i++)
            pq.push({nums[i], i});
        
        vector<int> ans;
        while(k--)
        {
            // cout<<pq.top().second<<" "<<pq.top().first<<endl;
            pq2.push({pq.top().second, pq.top().first});
            pq.pop();
        }

        while(pq2.size())
        {
            ans.push_back(pq2.top().second);
            pq2.pop();
        }
        return ans;


    }
};