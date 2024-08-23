class Solution {
public:
    int req=0;
    unordered_map<string, int> mp;
    bool valid(vector<int>& need, vector<int>& avail)
    {
        for(int i=0; i<need.size(); i++)
            if(need[i]<avail[i])
                return 0;

        return 1;
    }
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        if(req==0)
            return 0;
        
        string s="";
        for(int i=0; i<needs.size(); i++)
            s+=to_string(needs[i])+"_";
        
        if(mp.find(s)!=mp.end())
            return mp[s];
        int ans=0;
        for(int i=0; i<needs.size(); i++)
            ans+=needs[i]*price[i];

        for(int i=0; i<special.size(); i++)
        {
            if(!valid(needs, special[i]))
                continue;
            
            for(int j=0; j<needs.size(); j++)
            {
                needs[j]-=special[i][j];
                req-=special[i][j];
            }
            ans=min(ans, special[i].back()+solve(price, special, needs));
            for(int j=0; j<needs.size(); j++)
            {
                needs[j]+=special[i][j];
                req+=special[i][j];
            }
        }
        return mp[s]=ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        for(auto i: needs)
            req+=i;
        return solve(price, special, needs);
    }
};