class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n=username.size();

        unordered_map<string, map<long long, string>> userRecord;
        for(int i=0; i<n; i++)
            userRecord[username[i]][timestamp[i]]=website[i];
        
        map<string, int> freq;

        for(auto &user: userRecord)
        {
            vector<string> webs;
            for(auto &record: user.second)
                webs.push_back(record.second);
            
            unordered_set<string> seen;
            int rSz=webs.size();
            for(int i=0; i<rSz; i++)
                for(int j=i+1; j<rSz; j++)
                    for(int k=j+1; k<rSz; k++)
                        seen.insert(webs[i]+"#"+webs[j]+"#"+webs[k]);

            for(auto &s: seen)
                freq[s]++;
        }

        int maxFreq=0;
        string maxFreqString;

        for(auto &seq: freq)
        {
            if(seq.second > maxFreq)
            {
                maxFreq=seq.second;
                maxFreqString=seq.first;
            }
        }

        vector<string> ans;
        int start=0;
        int end=maxFreqString.find('#');

        while(end!=string::npos)
        {
            ans.push_back(maxFreqString.substr(start, end-start));
            start=end+1;
            end=maxFreqString.find('#', start);
        }
        ans.push_back(maxFreqString.substr(start, end-start));
        return ans;
    }
};