class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(auto &c: s)
        {
            if(c=='(' || c=='[' || c=='{')
                stk.push(c);
            
            else if(stk.empty() || (stk.top()=='(' && c!= ')') || 
                                    (stk.top()=='{' && c!= '}') || 
                                    (stk.top()=='[' && c!= ']'))
                return false;
            else
                stk.pop();
        }

        return stk.size()==0;
    }
};