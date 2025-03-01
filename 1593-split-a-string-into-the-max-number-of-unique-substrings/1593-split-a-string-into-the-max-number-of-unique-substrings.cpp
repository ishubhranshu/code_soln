class Solution {
public:
    int solve(int ind, string &s, unordered_set<string> used)
    {
        int n=s.length();
        if(ind==n)
            return 0;

        int ans=0;
        for(int i=ind; i<n; i++)
        {
            string word=s.substr(ind, i-ind+1);
            if(used.find(word)!=used.end())
                continue;
            used.insert(word);
            ans=max(ans, 1+solve(i+1, s, used));
            used.erase(word);
        }

        return ans;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> used;
        return solve(0, s, used);
    }
};