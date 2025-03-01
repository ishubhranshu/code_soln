class Solution {
public:
    string ans="";
    void solve(string &s, int &n, int &k)
    {
        if(k<0)
            return;
        if(s.length()==n)
        {
            k--;
            if(k==0)
                ans=s;
            return;
        }

        for(int c='a'; c<='c'; c++)
        {
            if(s!="" && s.back()==c)
                continue;
            s.push_back(c);
            solve(s, n, k);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string s="";
        solve(s, n, k);
        return ans;
    }
};