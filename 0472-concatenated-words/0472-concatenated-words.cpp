class Solution {
public:
    unordered_map<string, bool> mp;
    bool check(string &s, unordered_set<string> &st)
    {
        if(mp.find(s)!=mp.end())
            return mp[s];
        int n=s.length();
        for(int i=0; i<n; i++)
        {   
            string pre=s.substr(0, i+1);
            string rem=s.substr(i+1);
            
            if((st.find(pre)!=st.end()) && (st.find(rem)!=st.end()))
                return mp[s]=1;
            if((st.find(pre)!=st.end()) && check(rem, st))
                return mp[s]=1;
        }
        return mp[s]=0;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> ans;

        for(auto &s: words)
            if(check(s, st))
                ans.push_back(s);
        return ans;
    }
};