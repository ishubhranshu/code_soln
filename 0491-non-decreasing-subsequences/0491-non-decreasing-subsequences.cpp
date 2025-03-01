class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<int> &currEles, vector<vector<int>> &ans, int lastInd)
    {
        if(currEles.size()>1)
            ans.push_back(currEles);
        int n=nums.size();
        if(ind==n)
        {
            return;
        }
        unordered_set<int> used;
        for (int i = ind; i < n; i++) {
            if (used.find(nums[i]) != used.end() || (lastInd != -1 && nums[i] < nums[lastInd]))
                continue;
            used.insert(nums[i]);
            currEles.push_back(nums[i]);
            solve(i + 1, nums, currEles, ans, i);
            currEles.pop_back();
}


    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> currEles;
        vector<vector<int>> ans;
        solve(0, nums, currEles, ans, -1);
        return ans;
    }
};