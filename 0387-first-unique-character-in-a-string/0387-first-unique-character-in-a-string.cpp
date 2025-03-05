class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> lastInd;
        // int ans=-1;
        int n=s.length();
        for(int i=0; i<n; i++)
            lastInd[s[i]]++;

        for(int i=0; i<n; i++)
            if(lastInd[s[i]]==1)
                return i;
        
        return -1;
    }
};