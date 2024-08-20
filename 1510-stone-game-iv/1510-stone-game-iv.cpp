class Solution {
public:
    bool winnerSquareGame(int n) {
        if(n<2)
            return 1;
            
        vector<int> dp(n+1, 0);
        dp[0]=0;
        dp[1]=1;

        for(int i=2; i<=n; i++)
        {
            for(int f=1; f*f<=(i); f++)
            {
                int stns=f*f;
                if(dp[i-stns]==0)
                {
                    cout<<i<<" "<<stns<<endl;
                    dp[i]=1;
                    break;
                }
            }
        }

        return dp[n];
    }
};