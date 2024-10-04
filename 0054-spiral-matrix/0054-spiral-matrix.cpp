class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();

        int l=0, t=0, d=n-1, r=m-1;
        int dir=0;
        vector<int> ans;

        while(l<=r && d>=t)
        {
            if(dir==0)
            {
                for(int i=l; i<=r; i++)
                    ans.push_back(matrix[t][i]);
                t++;
            }
            else if(dir==1)
            {
                for(int i=t; i<=d; i++)
                    ans.push_back(matrix[i][r]);
                r--;
            }
            else if(dir==2)
            {
                for(int i=r; i>=l; i--)
                    ans.push_back(matrix[d][i]);
                d--;
            }
            else
            {
                for(int i=d; i>=t; i--)
                    ans.push_back(matrix[i][l]);
                l++;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};