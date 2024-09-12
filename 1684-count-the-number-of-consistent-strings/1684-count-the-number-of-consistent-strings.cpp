class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(auto i: allowed)
            st.insert(i);

        int ans=0;

        for(auto s: words)
        {
            int flag=1;
            for(auto i: s)
            {
                if(st.find(i)==st.end())
                {
                    flag=0;
                    break;
                }
            }
            ans+=flag;
        }

        return ans;
    }
};