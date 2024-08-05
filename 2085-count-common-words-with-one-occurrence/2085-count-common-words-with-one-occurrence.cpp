class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ans=0;
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        for(auto i: words1)
            mp1[i]++;
        
        for(auto i: words2)
            mp2[i]++;

        for(auto i: mp1)
            if(i.second==1 && mp2[i.first]==1)
                ans++;

        return ans;
        
        
    }
};