class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ump;
        for(auto i: s)
            ump[i]++;

        priority_queue<pair<int, char>> pq;
        for(auto i: ump)
            pq.push({i.second, i.first});

        string ans="";
        while(pq.size())
        {
            char ch=pq.top().second;
            int fr=pq.top().first;
            pq.pop();
            while(fr--)
                ans+=ch;
        }

        return ans;
    }
};