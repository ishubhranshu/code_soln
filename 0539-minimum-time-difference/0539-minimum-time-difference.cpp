class Solution {
public:
    int findMinDifference(vector<string>& t) {
        vector<int> ts;
        int ans=2000;
        for(auto i: t)
        {
            // cout<<60*stoi(i.substr(0, 2))+stoi(i.substr(3))<<endl;
            ts.push_back(60*stoi(i.substr(0, 2))+stoi(i.substr(3)));
        }
        sort(ts.begin(), ts.end());

        for(int i=0; i<ts.size(); i++)
        {
            int diff1 = abs(ts[i]-ts[(i+1)%ts.size()]);
            int diff2 = 1440 - diff1;
            ans=min(ans, min(diff1, diff2));
        }
        return ans;
    }
};