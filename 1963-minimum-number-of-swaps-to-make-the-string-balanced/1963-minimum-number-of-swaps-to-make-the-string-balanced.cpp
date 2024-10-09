class Solution {
public:
    int minSwaps(string s) {
        stack<int> stk;

        for(auto c: s)
        {
            if(c=='[')
                stk.push(c);
            else
            {
                if(stk.size() && stk.top()=='[')
                    stk.pop();
                else
                    stk.push(c);
            }
        }
        return (stk.size()/2+1)/2;
    }
};