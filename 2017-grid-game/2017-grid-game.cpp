class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long fr=0, sr=0;
        long long n=grid[0].size();
        grid[0][0]=0;
        for(int c=0; c<n; c++)
        {
            fr+=grid[0][c];
            sr+=grid[1][c];
        }

        long long tfr=0, tsr=sr;
        long long ans=0;
        for(int c=0; c<n; c++)
        {
            // cout<<fr-tfr<<" "<<sr-tsr<<endl;
            ans=max(ans, min(fr-tfr, sr-tsr));
            tfr+=grid[0][c];
            tsr-=grid[1][c];
        }     

        return ans;
    }
};