class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.first<b.first)
            return 1;

        if(a.first==b.first && a.second < b.second)
            return 1;

        return 0;
    }
    int conv(int n, vector<int> &mapping)
    {
        if(n==0)
            return 0;
        return 10*conv(n/10, mapping)+mapping[n%10];
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mp;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
                mp.push_back({mapping[0], i});
            else
            {
                int cnv = conv(nums[i], mapping);
                mp.push_back({cnv, i});

            }

            // cout<<i<<"->"<<cnv<<endl;
        }

        sort(mp.begin(), mp.end(), comp);

        vector<int> ans;
        for(auto i: mp)
            ans.push_back(nums[i.second]);


        return ans;
    }
};