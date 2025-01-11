class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();

        if(k==n)
            return 1;
        
        if(k>n)
            return 0;

        vector<int> freq(26, 0);

        for(auto c: s)
            freq[c-'a']++;

        int odd=0;
        for(auto f: freq)
            if(f%2)
                odd++;

        return odd<=k;
        
    }
};