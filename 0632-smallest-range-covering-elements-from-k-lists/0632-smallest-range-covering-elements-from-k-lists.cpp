class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int grt=INT_MIN;
        vector<int> ans{int(-1e6), int(1e6)};

        for(int i=0; i<nums.size(); i++)
        {
            pq.push({nums[i][0], {i, 0}});
            grt=max(grt, nums[i][0]);
        }

        while(1)
        {
            int arr=pq.top().second.first;
            int ind=pq.top().second.second;
            int ele=pq.top().first;;
            pq.pop();
            if(ans[1]-ans[0]>grt-ele)
            {
                ans[0]=ele;
                ans[1]=grt;
            }
            // cout<<grt<<" "<<ele<<endl;
            ind++;
            if(nums[arr].size()==ind)
                break;

            grt=max(grt, nums[arr][ind]);
            pq.push({nums[arr][ind], {arr, ind}});
        }

        return ans;
    }
};