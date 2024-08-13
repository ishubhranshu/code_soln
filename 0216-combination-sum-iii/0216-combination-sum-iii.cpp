class Solution {
public:
    vector<vector<int>> ans;
    void solve(int num, int k, int sum, vector<int> &cans)
    {
        if(cans.size()==k)
        {
            if(sum==0)
                ans.push_back(cans);
            return;
        }
        
        if(sum<0 || num>9)
            return;

        cans.push_back(num);
        solve(num+1, k, sum-num, cans);
        cans.pop_back();
        solve(num+1, k, sum, cans);
    
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45)
            return ans;
        vector<int> cans;
        solve(1, k, n, cans);
        return ans;
    }
};