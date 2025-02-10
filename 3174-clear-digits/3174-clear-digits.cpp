class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        
        for(auto &c: s)
        {
            if(c>='a' && c<='z')
                ans.push_back(c);
            else
                ans.pop_back();  
        }

        return ans;
    }
};