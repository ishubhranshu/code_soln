class Solution {
public:
    int solve(int ind, vector<int>& cookies, vector<int> &distribution)
    {
        int n=cookies.size();
        if(ind==n)
        {
            int ans=cookies[0];
            for(auto i: distribution)
            {
                // cout<<i<<" ";
                ans=max(i, ans);
            }
            // cout<<endl;
            return ans;
        }

        int ans=INT_MAX;
        int k=distribution.size();
        for(int kid=0; kid<k; kid++)
        {
            distribution[kid]+=cookies[ind];
            ans=min(ans, solve(ind+1, cookies, distribution));
            distribution[kid]-=cookies[ind];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribution(k, 0);
        return solve(0, cookies, distribution);
    }
};