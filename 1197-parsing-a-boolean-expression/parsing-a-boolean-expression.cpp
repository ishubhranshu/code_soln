class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> stk;
        for(auto c: exp)
        {
            if(c==',')
                continue;
            else if(c=='(' || c=='&' || c=='|' || c=='!' || c=='f' || c=='t')
                stk.push(c);
            else
            {
                bool t=0, f=0;
                while(!stk.empty())
                {
                    char cc=stk.top();
                    stk.pop();

                    if(cc=='f')
                        f=1;
                    else if(cc=='t')
                        t=1;
                    else if(cc='(')
                    {
                        char op=stk.top();
                        stk.pop();
                        if(op=='&')
                        {
                            if(f)
                                stk.push('f');
                            else
                                stk.push('t');
                        }
                        else if(op=='|')
                        {
                            if(t)
                                stk.push('t');
                            else
                                stk.push('f');
                        }
                        else
                        {
                            if(f)
                                stk.push('t');
                            else
                                stk.push('f');
                        }
                        break;
                    }
                }
            }

        }
        // cout<<stk.size();
        // return stk.size();
        if(stk.top()=='f')
            return 0;
        return 1; 
    }
};