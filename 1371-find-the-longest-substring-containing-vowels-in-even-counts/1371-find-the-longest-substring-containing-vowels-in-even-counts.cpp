class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;
        mp[0]=-1;
        int c=0;
        int ans=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='a')
                c^=1<<0;
            else if(s[i]=='e')
                c^=1<<1;
            else if(s[i]=='i')
                c^=1<<2;
            else if(s[i]=='o')
                c^=1<<3;
            else if(s[i]=='u')
                c^=1<<4;

            if(mp.find(c)!=mp.end())
                ans=max(ans, i-mp[c]);
            else
                mp[c]=i;
        }

        return ans;
    }
};