class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(auto i: amount)
            if(i)
                pq.push(i);

        int ans=0;

        

        while(pq.size()>1)
        {
            ans++;
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            cout<<first<<" "<<second<<endl;
            first--;
            second--;
            
            if(first!=0)
                pq.push(first);
            if(second!=0)
                pq.push(second);
        }
        if(pq.empty())
            return ans;
        return ans+pq.top();
    }
};