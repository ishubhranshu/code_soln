class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size=0;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        int i=0, n=nums.size();
        while(pq.size()<k && i<n)
            pq.push(nums[i++]);
        while(i<n)
        {
            if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i++]);
            }
            else
            {
                i++;
            }
        }
    }
    
    int add(int val) {
        // cout<<val<<" ";
        // if(pq.size())
        //     cout<<pq.top()<<endl;
        
        if(pq.size()<size)
            pq.push(val);
        else if(val>pq.top())
        {
            if(!pq.empty())
                pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */