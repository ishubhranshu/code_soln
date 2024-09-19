class Solution {
public:
    int solve(int a, int b, char o)
    {
        if(o=='+')
            return a+b;
        if(o=='-')
            return a-b;
        return a*b;
    }
    vector<int> diffWaysToCompute(string e) {
        vector<int> ans;
        for(int i=0; i<e.length(); i++)
        {
            if(e[i]=='+' || e[i]=='*' || e[i]=='-')
            {
                vector<int> left = diffWaysToCompute(e.substr(0, i));
                vector<int> right = diffWaysToCompute(e.substr(i+1));

                for(auto k: left)
                {    
                    for(auto j: right)
                    {
                        if(e[i]=='*')
                            ans.push_back(k*j);
                        else if(e[i]=='+')
                            ans.push_back(k+j);
                        else
                            ans.push_back(k-j);
                    }
                }
            }
        }
        if(ans.size()==0)
            ans.push_back(stoi(e));
        return ans;
    }
};