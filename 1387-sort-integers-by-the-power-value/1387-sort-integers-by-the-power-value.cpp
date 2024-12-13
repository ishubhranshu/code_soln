class Solution {
public:
    int pwr(int x)
    {
        if(x==1)
            return 0;

        if(x%2==0)
            return 1+pwr(x/2);

        return 1+pwr(3*x+1);
    }
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=lo; i<=hi; i++)
        {
            // cout<<i<<" "<<pwr(i)<<endl;
            pq.push({pwr(i), i});
        }
        
        k--;
        while(k--)
            pq.pop();

        return pq.top().second;
    }
};