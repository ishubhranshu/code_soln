
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> freq;
        vector<vector<int>> freqCount(n+1);
        vector<int> ans;
        
        for(auto num: nums)
            freq[num]++;

        for(auto f: freq)
            freqCount[f.second].push_back(f.first);

        for(int ind=n; ind>=0; ind--)
        {
            int sz=freqCount[ind].size();
            for(int i=0; i<sz; i++)
            {
                ans.push_back(freqCount[ind][i]);
                k--;
                if(k==0)
                    break;
            }
            if(k==0)
                break;
        }
        return ans;
    }
};