class Solution {
public:
    bool solve(unordered_set<string> &givenStr, string &s, int &n)
    {
        if(s.length()==n)
            return givenStr.find(s) == givenStr.end();

        s.push_back('0');
        if(solve(givenStr, s, n))
            return true;
        s.pop_back();
        
        s.push_back('1');
        if(solve(givenStr, s, n))
            return true;
        s.pop_back();

        return false;
        

    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> givenStr(nums.begin(), nums.end());
        int n=nums[0].length();
        string s="";
        solve(givenStr, s, n);
        return s;
    }
};