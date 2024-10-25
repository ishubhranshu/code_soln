class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);

        for(int i=1; i<folder.size(); i++)
        {
            string stf=ans.back();
            stf+='/';
            if(folder[i].find(stf)!=0)
                ans.push_back(folder[i]);
        }

        return ans;
    }
};