class Solution {
public:
    bool check(vector<int> &freq1, vector<int> &freq2)
    {
        for(int i=0; i<26; i++)
            if(freq1[i]!=freq2[i])
                return 0;
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq1(26, 0), freq2(26, 0);
        vector<int> ans;
        if(p.length()>s.length())
            return {};

        for(auto c: p)
            freq1[c-'a']++;

        int i=0, j=0;
        for(j; j<p.length(); j++)
            freq2[s[j]-'a']++;
        j--;
        while(1)
        {
            // cout<<i<<' '<<j<<endl;
            if(check(freq1, freq2))
                ans.push_back(i);
            if(j==s.length()-1)
                break;
            freq2[s[i]-'a']--;
            i++;
            j++;
            freq2[s[j]-'a']++;
        }

        return ans;
    }
};