class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        int n=times.size();
        t=times[t][0];
        sort(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occ;
        priority_queue<int, vector<int>, greater<int>> free;
        int chair=0;
        
        for(int i=0; i<n; i++)
        {
            while(!occ.empty() && occ.top().first <= times[i][0])
            {
                free.push(occ.top().second);
                occ.pop();
                
            }
            if(free.empty())
            {
                if(times[i][0]==t)
                    return chair;
                occ.push({times[i][1], chair++});
            }
            else
            {
                if(times[i][0]==t)
                    return free.top();
                
                occ.push({times[i][1], free.top()});
                free.pop();
            }
        }

        return -1;


    }
};