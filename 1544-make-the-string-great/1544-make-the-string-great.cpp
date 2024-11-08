class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;

        for(auto i: s)
        {
            if(!stk.empty() && (stk.top()==i-('A'-'a') || stk.top()==i+('A'-'a')))
                stk.pop();
            else
                stk.push(i);
        }
        s="";
        while(!stk.empty())
        {
            s=stk.top()+s;
            stk.pop();
        }
        return s;
    }
};