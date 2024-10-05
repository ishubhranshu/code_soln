class Solution {
public:
    bool check(vector<int> freq1, vector<int> freq2)
    {
        for(int i=0; i<26; i++)
            if(freq1[i]!=freq2[i])
                return 0;

        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return 0;
        vector<int> freq1(26, 0), freq2(26,0);


        for(auto c: s1)
            freq1[c-'a']++;

        int i=0, j=0;
        for(j; j<s1.size(); j++)
            freq2[s2[j]-'a']++;
        j--;
        while(1)
        {
            // cout<<i<<" "<<j<<endl;
            if(check(freq1, freq2))
                return 1;
            if(j==s2.length()-1)
                break;
            freq2[s2[i]-'a']--;
            i++;
            j++;
            freq2[s2[j]-'a']++;
        }
        
        return 0;
    }
};