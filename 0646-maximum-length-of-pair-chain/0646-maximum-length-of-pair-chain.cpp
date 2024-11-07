class Solution {
public:
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
    
        sort(pairs.begin(), pairs.end(), comp);
        int laste=INT_MIN, ans=0;
        for(auto i: pairs)
        {
            if(laste<i[0])
            {
                ans++;
                laste=i[1];
            }
        }

        return ans;
    }
};