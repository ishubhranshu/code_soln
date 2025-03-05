class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<int> stk;
        int n=temps.size();
        vector<int> ans(n, 0);
        for(int i=n-1; i>=0; i--)
        {
            while(!stk.empty() && temps[stk.top()]<=temps[i])
                stk.pop();

            if(!stk.empty())
                ans[i]=stk.top()-i;
            stk.push(i);
        }
        
        return ans;
    }
};