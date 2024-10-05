class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> ump;
        int n=mat.size(), m=mat[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                ump[i-j].push_back(mat[i][j]);

        for(auto &it: ump)
            sort(it.second.begin(), it.second.end());

        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                mat[i][j]=ump[i-j].back();
                ump[i-j].pop_back();
            }
        }

        return mat;
    }
};