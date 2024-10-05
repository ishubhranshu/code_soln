class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        // cout<<n<<" "<<m<<endl<<endl;
        vector<int> ans;
        for(int sum=0; sum<m+n-1; sum++)
        {
            int i,j;
            if(sum%2==0)
            {
                i=min(sum, n-1);
                j=sum-i;
                while(j<m && i>=0)
                {
                    // cout<<i<<" "<<j<<endl;
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }
            else
            {
                j=min(sum, m-1);
                i=sum-j;
                while(i<n  && j>=0)
                {
                    // cout<<i<<" "<<j<<endl;
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
            // cout<<i<<" "<<j<<endl;
            // cout<<endl;
        }

        return ans;
    }
};