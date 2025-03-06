class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char, int> freqs;

        int maxCount=0;
        int maxCountChar;
        for(auto &c: s)
        {
            freqs[c]++;
            if(freqs[c]>(n+1)/2)
                return "";
            if(maxCount<freqs[c])
            {
                maxCount=freqs[c];
                maxCountChar=c;
            }
        } 
        
        string ans(n, '_');
        int ind=0;

        while(freqs[maxCountChar]!=0)
        {
            ans[ind]=maxCountChar;
            freqs[maxCountChar]--;
            ind+=2;
        }
        freqs.erase(maxCountChar);

        for(auto freq: freqs)
        {
            for(int i=0; i<freq.second; i++)
            {
                if(ind>=n)
                    ind=1;
                ans[ind]=freq.first;
                ind+=2;
            }
        }

        return ans;
    }
};