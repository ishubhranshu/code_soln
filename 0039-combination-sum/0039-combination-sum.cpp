class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind, int trgt, vector<int>& candidates, vector<int>& cans)
    {
        if(trgt==0)
        {
            ans.push_back(cans);
            return;
        }
        if(ind==candidates.size() || trgt<0)
            return;

        cans.push_back(candidates[ind]);
        solve(ind, trgt-candidates[ind], candidates, cans);
        cans.pop_back();
        solve(ind+1, trgt, candidates, cans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cans;
        solve(0, target, candidates, cans);
        return ans;
    }
};