class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mn=INT_MAX;
        long long sum=0, count=0;

        for(auto i: matrix)
        {
            for(auto j: i)
            {
                if(j<0)
                    count++;
                sum+=abs(j);
                mn=min(mn, abs(j));
            }
        }
        // cout<<count<<" "<<mn;
        return (count%2) ? sum-2*mn : sum;
    }
};