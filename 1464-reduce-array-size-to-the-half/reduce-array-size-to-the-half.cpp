class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> ump;

        for(auto i: arr)
            ump[i]++;
        int n=arr.size();
        int m=0;
        int ans=0;
        priority_queue<int> pq;
        for(auto i: ump)
            pq.push(i.second);

        while(m<n/2)
        {
            ans++;
            m+=pq.top();
            pq.pop();
        }

        return ans;
    }
};