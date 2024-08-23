class Solution {
public:
    vector<int> used;
    int solve(int cnum, int &num)
    {
        if(cnum>num)
            return 1;

        int ans=0;
        for(int i=1; i<=num; i++)
        {
            if(used[i]==-1 && (cnum%i==0 || i%cnum==0))
            {
                used[i]=1;
                ans+=solve(cnum+1, num);
                used[i]=-1;
            }
        }

        return ans;
    }
    int countArrangement(int n) {
        used.resize(n+1, -1);
        return solve(1, n);
    }
};