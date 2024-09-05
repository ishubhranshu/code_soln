class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int osum = 0;
        for(auto i: rolls)
            osum+=i;

        int reqsum = mean*(n+rolls.size())-osum;

        cout<<reqsum<<" "<<reqsum/n<<endl;
        if(reqsum>n*6 || reqsum<0 || !(reqsum/n))
            return {};

        vector<int> ans, temp(n, reqsum/n);
        ans.insert(ans.begin(), temp.begin(), temp.end());
        int rem=reqsum%n, i=0;
        while(rem--)
        {
            ans[i]++;
            i=(i+1)%ans.size();
        }
        return ans;
    }
};