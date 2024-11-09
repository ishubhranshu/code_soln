class Solution {
public:
    bool check(string s)
    {
        bool f1=0, f2=0;
        for(int i=0; i<s.length(); i++)
            if(s[i]>s[i+1])
                f1=1;

        for(int i=0; i<s.length(); i++)
            if(s[i]<s[i+1])
                f2=1;
        
        return f1 && f2;
    }
    int minDeletionSize(vector<string>& strs) {
        if(strs[0].length()<2)
            return 0;
        int ans=0;
        for(auto &s: strs)
        {
            if(!check(s))
                ans++;
        }
        return ans;
    }
};