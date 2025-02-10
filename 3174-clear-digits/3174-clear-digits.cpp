class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;

        for(auto &c: s)
        {
            if(c>='a' && c<='z')
                stk.push(c);
            else
                stk.pop();
        }
        string ans="";
        while(!stk.empty())
        {
            ans=stk.top()+ans;
            stk.pop();
        }

        return ans;
    }
};