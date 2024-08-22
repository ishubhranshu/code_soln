class Solution {
public:
    int K;
    int solve(int ind, vector<int>& dist, vector<int>& cookies, int k)
    {
        // cout<<ind<<endl;
        if(ind==cookies.size())
        {
            int ans=INT_MIN;
            for(auto i: dist)
            {
                // cout<<i<<" ";
                ans=max(ans, i);
            }    
            // cout<<endl;
            return ans;
        }

        int ans=INT_MAX;
        for(int i=0; i<k; i++)
        {
            if(K!=0 && dist[i])
            {
                for(auto ii: dist)
                {
                    // cout<<ii<<" ";
                }
                // cout<<endl;
            }
            //     continue;
            K/=2;
            dist[i]+=cookies[ind];
            ans=min(ans, solve(ind+1, dist, cookies, k));
            dist[i]-=cookies[ind];
            K*=2;
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        K=(1<<k)-1;
        // cout<<K<<"="<<endl;
        vector<int> dist(k, 0);
        return solve(0, dist, cookies, k);
    }
};