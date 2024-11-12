class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<int> ans;
        int maxBeauty = items[0][1];
        for (int i = 0; i < items.size(); i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }
        for(auto q: queries)
        {
            int a=0;
            int l=0, r=items.size()-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(items[mid][0] <= q)
                {
                    a=max(a, items[mid][1]);
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            ans.push_back(a);
            // cout<<q<<" "<<ans<<endl;
            // cout<<q<<" "<<l<<" "<<r<<endl;
        }
        return ans;
    }
};