class Solution {
public:
    unordered_set<string> st;
    int solve(int ind, string &s, string curr)
    {
        if(ind==s.size())
            return st.size();
        int ans=0;
        curr+=s[ind];

        if(st.find(curr)==st.end())
        {
            st.insert(curr);
            ans=max(ans, solve(ind+1, s, ""));
            st.erase(curr);
        }
        ans=max(ans, solve(ind+1, s, curr));
        return ans;
    }
    int maxUniqueSplit(string s) {
        return solve(0, s, "");
    }
};