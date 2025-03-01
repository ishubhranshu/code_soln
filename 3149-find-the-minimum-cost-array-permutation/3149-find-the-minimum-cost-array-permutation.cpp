class Solution {
public:
    int ans=INT_MAX;
    vector<int> ansVect;
    void solve(vector<int>& nums, vector<int>& perm, vector<bool> &used, int score)
    {
        if(score>=ans)
            return;
        int n=nums.size();
        if(perm.size()==n)
        {
            score+=abs(perm.back()-nums[perm[0]]);
            if(score<ans)
            {
                ans=score;
                ansVect=perm;
            }
            return;
        }

        for(int i=1; i<n; i++)
        {
            if(used[i]==1)
                continue;
            used[i]=1;
            perm.push_back(i);
            int s=perm.size();
            solve(nums, perm, used, score+abs(perm[s-2]-nums[perm[s-1]]));
            perm.pop_back();
            used[i]=0;
        }
    }
    vector<int> findPermutation(vector<int>& nums) {
        int n=nums.size();
        vector<bool> used(n, 0);
        vector<int> perm;
        perm.push_back(0);
        used[0]=1;
        solve(nums, perm, used, 0);

        cout<<ans;
        return ansVect;
    }
};