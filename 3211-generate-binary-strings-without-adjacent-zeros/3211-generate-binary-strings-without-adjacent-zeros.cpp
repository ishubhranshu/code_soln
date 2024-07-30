class Solution {
public:
    void generate(string &s, int &n, vector<string> &ans)
    {
        if(s.length()==n)
        {
            ans.push_back(s);
            return;
        }

        if(s.length()==0 || s.back()!='0')
        {
            s+='0';
            generate(s, n, ans);
            s.pop_back();
        }
        s+='1';
        generate(s, n, ans);
        s.pop_back();
    }
    vector<string> validStrings(int n) {
        string s="";
        vector<string> ans;
        generate(s, n, ans);
        return ans;
    }
};