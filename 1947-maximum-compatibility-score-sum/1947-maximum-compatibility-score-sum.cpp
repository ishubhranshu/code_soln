class Solution {
public:
    vector<int> used;
    int nques;
    int solve(int ind, int nstd, vector<vector<int>>& std, vector<vector<int>>& mnt)
    {
        if(ind==nstd)
        {
            int scr=0;
            for(int i=0; i<nstd; i++)
            {
                for(int j=0; j<nques; j++)
                    if(std[i][j]==mnt[used[i]][j])
                        scr++;
            }
            return scr;

        }

        int ans=0;
        for(int i=0; i<nstd; i++)
        {
            if(used[i]!=-1)
                continue;;
            used[i]=ind;
            ans=max(ans, solve(ind+1, nstd, std, mnt));
            used[i]=-1;
        }
        return ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& std, vector<vector<int>>& mnt) {
        int nstd=std.size();
        nques=std[0].size();
        used.resize(nstd, -1);

        return solve(0, nstd, std, mnt);

    }
};