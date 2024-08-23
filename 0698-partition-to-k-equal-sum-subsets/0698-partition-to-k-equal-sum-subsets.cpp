class Solution {
public:
    vector<int> used;
    int rsum;
    bool solve(int ind, int csum, int k, vector<int>& stks)
    {
        if(k==0)
            return 1;
        
        if(csum==rsum)
            return solve(0, 0, k-1, stks);

        for(int i=ind; i<stks.size(); i++)
        {
            if(csum+stks[i]>rsum || used[i])
                continue;
            used[i]=1;
            if(solve(i+1, csum+stks[i], k, stks))
                return 1;
            used[i]=0;
        }

        return 0;
    }
    bool canPartitionKSubsets(vector<int>& stks, int k) {
        int total=0;
        for(auto i: stks)
            total+=i;

        if(total%k || stks.size()<k)
            return 0;

        rsum=total/k;
        used.resize(stks.size(), 0);

        return solve(0, 0, k, stks);
    }
};