class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        if(n==1)
            return 1;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> st;
        vector<long long> pf{a,b,c};
        // pq.push(a);
        // st.insert(a);
        // pq.push(b);
        // st.insert(b);
        // pq.push(c);
        // st.insert(c);
        long long count=1;

        while(count<=n)
        {
            if(pq.size())
            {
                long long cele=pq.top();
                pq.pop();
                // cout<<cele<<endl;
                for(auto p: pf)
                {
                    long long nele=count*p;
                    if(st.find(nele)==st.end())
                    {
                        st.insert(nele);
                        pq.push(nele);
                    }
                }
            }
            else
            {
                for(auto p: pf)
                {
                    long long nele=count*p;
                    if(st.find(nele)==st.end())
                    {
                        st.insert(nele);
                        pq.push(nele);
                    }
                }  
            }
            count++;
        }

        return pq.top();
    }
};