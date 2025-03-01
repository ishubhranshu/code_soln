class Solution {
public:
    vector<int> solve(int start, int end, string &expression)
    {

        vector<int> nums;

        for(int i=start; i<end; i++)
        {
            if(expression[i]=='-' || expression[i]=='+' || expression[i]=='*')
            {
                vector<int> left= solve(start, i-1, expression);
                vector<int> right= solve(i+1, end, expression);

                for(auto l: left)
                {
                    for(auto r: right)
                    {
                        if(expression[i]=='-')
                            nums.push_back(l-r);
                        if(expression[i]=='+')
                            nums.push_back(l+r);
                        if(expression[i]=='*')
                            nums.push_back(l*r);
                    }
                }
            }
        }
        if(nums.size()==0)
            nums.push_back(stoi(expression.substr(start, end-start+1)));
        return nums;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.length();
        return solve(0, n-1, expression);
    }
};