class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        long long numEles=n*n;

        long long reqSum=(numEles*(numEles+1))/2;
        long long reqSqrSum=(numEles*(numEles+1LL)*(2*numEles+1LL))/6;
        
        long long givenSum=0;
        long long givenSqrSum=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                givenSum+=grid[i][j];
                givenSqrSum+=grid[i][j]*grid[i][j];
            }
        }

        long long diff=reqSum-givenSum;
        long long sqrDiff=reqSqrSum-givenSqrSum;

        int A=(diff+sqrDiff/diff)/2;
        int B=A-diff;

        return {B,A};
    }
};