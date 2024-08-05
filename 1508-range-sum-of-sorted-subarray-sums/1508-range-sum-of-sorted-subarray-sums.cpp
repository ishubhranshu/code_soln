class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<n; i++)
            pq.push({nums[i], i});
        int ans=0, ci=0;
        int mod=1e9+7;
        while(!pq.empty())
        {
            int sum=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            ci++;
            if(left<=ci)
                ans=(ans+sum)%mod;
            if(right==ci)
                break;

            if(ind!=n-1)
                pq.push({sum+nums[ind+1], ind+1});
        }

        return ans;
    }
};