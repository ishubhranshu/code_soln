class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long long score=0;
        int n=nums.size();
        for(int i=0; i<n; i++)
            pq.push({nums[i], i});


        while(!pq.empty())
        {
            int ind=pq.top().second;
            int ele=pq.top().first;

            pq.pop();

            if(nums[ind]<0)
                continue;

            score+=ele;
            nums[ind]=-1;
            if(ind-1>=0)
                nums[ind-1]=-1;
            if(ind+1<n)
                nums[ind+1]=-1;
        }

        return score;
    }
};