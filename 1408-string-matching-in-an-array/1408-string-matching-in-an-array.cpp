class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n=words.size();
        unordered_set<string> ust;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                string s1=words[j];
                string s2=words[i];
                if(s1.find(s2)!=string::npos && ust.find(s2)==ust.end())
                {
                    ust.insert(s2);
                    ans.push_back(s2);
                }
            }   
        }

        return ans;
        
    }
};