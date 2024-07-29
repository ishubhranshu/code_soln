class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0, n=rating.size();
        for(int i=1; i<n-1; i++)
        {
            int left=i-1, right=i+1;
            int ll=0, rl=0, lg=0, rg=0;
            while(left>=0)
            {   
                if(rating[left]>rating[i])
                    lg++;
                if(rating[left]<rating[i])
                    ll++;
                left--;
            }
            while(right<n)
            {   
                if(rating[right]>rating[i])
                    rg++;
                if(rating[right]<rating[i])
                    rl++;
                right++;
            }
            ans+=ll*rg+lg*rl;
        }

        return ans;
    }
};