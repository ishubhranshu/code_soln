class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int, pair<int, int>> mp;

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                mp[mat[i][j]]={i, j};
        
        vector<int> rows(n, 0), cols(m, 0);

        for(int i=0; i<arr.size(); i++)
        {
            int x=mp[arr[i]].first;
            int y=mp[arr[i]].second;

            rows[x]++;
            cols[y]++;

            if(rows[x]==m || cols[y]==n)
                return i;
        }

        return -1;
    }
};