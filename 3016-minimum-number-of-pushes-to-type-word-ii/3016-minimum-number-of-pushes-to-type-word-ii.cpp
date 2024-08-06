class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> ump;
        for(auto c: word)
            ump[c]++;

        // if(ump.size()<=8)
            // return word.length();


        priority_queue<pair<int, char>> pq;
        for(auto i: ump)
            pq.push({i.second, i.first});

        int ans=0;
        int count=0;
        while(!pq.empty())
        {
            count++;
            int freq=pq.top().first;
            pq.pop();

            if(count<=8)
                ans+=freq;
            else if(count<=16)
                ans+=2*freq;
            else if(count<=24)
                ans+=3*freq;
            else
                ans+=4*freq;
        }

        return ans;
    }
};