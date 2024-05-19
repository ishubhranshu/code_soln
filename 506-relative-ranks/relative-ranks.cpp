class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; i++)
            pq.push({score[i], i});

        vector<string> ans(n);
        int counter=1;
        while(pq.size())
        {
            int ind=pq.top().second;
            pq.pop();
            if(counter==1)
                ans[ind]="Gold Medal";
            else if(counter==2)
                ans[ind]="Silver Medal";
            else if(counter==3)
                ans[ind]="Bronze Medal";
            else
                ans[ind]=to_string(counter);

            counter++;
        }

        return ans;
    }
};