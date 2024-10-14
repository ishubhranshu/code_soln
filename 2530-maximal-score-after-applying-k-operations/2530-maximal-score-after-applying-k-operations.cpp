class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i: nums)
            pq.push(i);
        long long score=0;
        while(k--)
        {
            score+=pq.top();
            int top=pq.top();
            pq.pop();
            int nele=top/3;
            if(top%3)
                nele++;
            pq.push(nele);
        }

        return score;
    }
};