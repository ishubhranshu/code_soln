class Solution {
public:
    bool isVowel(char c)
    {
        return c=='a' || c=='e' || c=='o' || c=='i' || c=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size(), m=queries.size();
        // cout<<"n: "<<n<<endl;
        // cout<<"m: "<<m<<endl;
        vector<int> counts(n, 0);
        vector<int> ans(m, 0);
        counts[0]=isVowel(words[0][0]) && isVowel(words[0].back());
        for(int i=1; i<n; i++)
        {
            if(isVowel(words[i][0]) && isVowel(words[i].back()))
                counts[i]=counts[i-1]+1;
            else
                counts[i]=counts[i-1];
            // cout<<i<<endl;
        }

        // for(auto i: counts)
        //     cout<<i<<" ";
        // cout<<endl;

        for(int i=0; i<m; i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            
            if((l-1)<0)
                ans[i]=counts[queries[i][1]];
            else
                ans[i]=counts[r]-counts[l-1];
        }
        return ans;
    }
};