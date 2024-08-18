class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> st;
        vector<long long> pf{2,3,5};
        pq.push(1);
        st.insert(1);
        long long count=1;

        while(count<n)
        {
            long long cele=pq.top();
            pq.pop();
            for(auto p: pf)
            {
                long long nele=p*cele;
                if(st.find(nele)==st.end())
                {
                    st.insert(nele);
                    pq.push(nele);
                }
            }
            count++;
            // cout<<count<<" "<<n<<endl;
            // if(count>10)
            //     break;
        }

        return pq.top();
    }
};