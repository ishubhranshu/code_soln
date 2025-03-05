class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        for(auto ast: asteroids)
        {
            if(ast<0)
            {
                while(!stk.empty() && stk.top()>0 && abs(stk.top())<abs(ast))
                    stk.pop();
                if(stk.empty())
                    stk.push(ast);
                else
                {
                    if(stk.top()<0)
                        stk.push(ast);
                    else if(abs(stk.top())==abs(ast))
                        stk.pop();
                }
                
            }
            else
                stk.push(ast);
        }
        vector<int> ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};