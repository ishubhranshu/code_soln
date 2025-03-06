class Solution {
public:
    string sorted(string &s)
    {
        vector<int> freq(26, 0);
        for(auto c: s)
            freq[c-'a']++;

        string srted="";
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<freq[i]; j++)
                srted+=('a'+i);
        }
        return srted;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;

        for(auto str: strs)
            ump[sorted(str)].push_back(str);

        vector<vector<string>> ans;

        for(auto i: ump)
        {
            vector<string> temp;
            for(auto s: i.second)
                temp.push_back(s);
            ans.push_back(temp);
        }

        return ans;
    }
};