class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

        string ans="";
        if(a)   pq.push({a, 'a'});
        if(b)   pq.push({b, 'b'});
        if(c)   pq.push({c, 'c'});

        while(1)
        {
            char c=pq.top().second;
            int f=pq.top().first;
            pq.pop();
            // cout<<c<<" "<<f<<endl;
            int n=ans.length();
            if(n>1 && ans[n-1]==ans[n-2] && ans[n-1]==c)
            {
                if(pq.size()==0)
                    break;
                
                char c2=pq.top().second;
                int f2=pq.top().first;
                pq.pop();
                
                ans+=c2;
                f2--;
                pq.push({f, c});
                if(f2)
                    pq.push({f2, c2});
            }
            else
            {
                ans+=c;
                f--;
                if(f)
                    pq.push({f, c});
            }
            if(pq.empty())
                break;
        }

        return ans;
    }
};