class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind, int trgt, vector<int>& candidates, vector<int> &cans)
    {
        if(trgt==0)
        {
            ans.push_back(cans);
            return;
        }
        if(ind==candidates.size() || trgt<0)
            return;

        for(int i=ind; i<candidates.size(); i++)
        {
            if(i!=ind && candidates[i]==candidates[i-1])
                continue;
            cans.push_back(candidates[i]);
            solve(i+1, trgt-candidates[i], candidates, cans); 
            cans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(0, target, candidates, temp);

        return ans;
    }
};