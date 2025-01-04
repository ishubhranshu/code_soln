class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> left(26, -1), right(26,-1);
        int n=s.length();
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(left[s[i]-'a']==-1)
                left[s[i]-'a']=i;
            right[s[i]-'a']=i;
        }

        for(int i=0; i<26; i++)
        {
            int start=left[i];
            int end=right[i];
            if(start==-1 || end<=start)
                continue;

            unordered_set<char> ust;

            for(int ind=start+1; ind<end; ind++)
                if(ust.find(s[ind])==ust.end())
                    ust.insert(s[ind]);
                
            ans+=ust.size();
        }
        return ans;
    }
};