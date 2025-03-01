class Solution {
public:
    bool solve(int ind, int &n, vector<int> &ans, unordered_set<int> &used)
    {
        int len=ans.size();
        if(ind==len)
            return true;
        
        if(ans[ind]!=0)
            return solve(ind+1, n, ans, used);

        for(int i=n; i>0; i--)
        {
            if(used.find(i) != used.end())
                continue;

            if(i!=1)
                if(ind+i >= len || ans[ind+i]!=0)
                    continue;
            
            used.insert(i);
            ans[ind]=i;
            if(i!=1)
                ans[ind+i]=i;
            if(solve(ind+1, n, ans, used))
                return true;
            ans[ind]=0;
            if(i!=1)
                ans[ind+i]=0;
            
            used.erase(i);
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int len=2*(n-1)+1;
        vector<int> ans(len, 0);
        unordered_set<int> used;
        solve(0, n, ans, used);
        return ans;

    }
};