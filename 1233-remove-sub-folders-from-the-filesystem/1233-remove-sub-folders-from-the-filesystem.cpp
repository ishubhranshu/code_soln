class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(folder.begin(), folder.end());
        vector<string> ans;

        for(auto f: folder)
        {
            string temp=f;
            bool unique=1;
            while(temp!="")
            {
                // cout<<temp<<endl;
                int ind=temp.find_last_of('/');
                temp=temp.substr(0, ind);
                if(st.find(temp)!=st.end())
                {
                    unique=0;
                    break;
                }
            }
            if(unique)
                ans.push_back(f);
        }
        return ans;

    }
};