class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k>nums.size())
            return -1;
        priority_queue<int> pq;
        for(auto i:nums)
            pq.push(i);

        while(--k)
            pq.pop();

        return pq.top();
    }
};