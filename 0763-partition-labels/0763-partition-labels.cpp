class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lind=0, size=0, n=s.length();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++)
            mp[s[i]]=i;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(lind<mp[s[i]])
                lind=mp[s[i]];

            size++;

            if(lind==i)
            {
                ans.push_back(size);
                size=0;
            }
        }
        return ans;
    }
};