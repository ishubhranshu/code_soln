class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char, int> freqs;

        for(auto &c: s)
        {
            freqs[c]++;
            if(freqs[c]>(n+1)/2)
                return "";
        } 

        priority_queue<pair<int, char>> pq;
        for(auto freq: freqs)
        {
            pq.push({freq.second, freq.first});
        }

        string ans(n, '_');
        int ind=0;

        while(!pq.empty())
        {
            char topChar=pq.top().second;
            int topFreq=pq.top().first;
            pq.pop();
            
            while(ind<n && topFreq--)
            {
                ans[ind]=topChar;
                ind+=2;
                if(ind>=n)
                    ind=1;
            }
        }

        return ans;
    }
};