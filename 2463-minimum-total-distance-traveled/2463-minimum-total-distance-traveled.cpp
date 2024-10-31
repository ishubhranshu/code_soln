class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(int indr, int indf, vector<int>& facts, vector<int>& robot)
    {
        if(indr==robot.size())
            return 0;
        if(indf==facts.size())
            return -2;

        if(dp[indr][indf]!=-1)
            return dp[indr][indf];
        
        long long ntake=solve(indr, indf+1, facts, robot);
        long long take=solve(indr+1, indf+1, facts, robot);
        long long ans;
        if(ntake==-2 && take==-2)
            ans=-2;
        else if(ntake==-2)
            ans=abs(robot[indr]-facts[indf])+take;
        else if(take==-2)
            ans=ntake;
        else
            ans=min(ntake, abs(robot[indr]-facts[indf])+take);
        
        return dp[indr][indf]=ans;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> facts;
        for(auto i: factory)
            for(int j=0; j<i[1]; j++)
                facts.push_back(i[0]);

        sort(facts.begin(), facts.end());
        sort(robot.begin(), robot.end());
        dp.resize(robot.size(), vector<long long>(facts.size(), -1));
        return solve(0, 0, facts, robot);

    }
};