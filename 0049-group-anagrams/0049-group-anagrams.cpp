class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(auto &s: strs)
        {
            string sortedS=s;
            sort(sortedS.begin(), sortedS.end());
            groups[sortedS].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto &group: groups)
        {
            vector<string> grp;
            for(auto &s: group.second)
                grp.push_back(s);

            ans.push_back(grp);
        }

        return ans;
    }
};