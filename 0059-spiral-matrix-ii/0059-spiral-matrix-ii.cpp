class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m=n;
        vector<vector<int>> mat(m, vector<int>(n, -1));
        int left=0, right=n-1, low=m-1, high=0;
        int r=0, c=0;
        int val=1;
        while(left<=right && high<=low)
        {
            while(c<=right)
            {
                // cout<<r<<" "<<c<<" "<<ptr->val<<endl;
                mat[r][c]=val++;
                c++;
            }
            high++;
            r++;
            c--;
            while(r<=low)
            {
                // cout<<r<<" "<<c<<" "<<ptr->val<<endl;
                mat[r][c]=val++;
                r++;
            }
            right--;
            r--;
            c--;
            while(c>=left)
            {
                // cout<<r<<" "<<c<<" "<<ptr->val<<endl;
                mat[r][c]=val++;
                c--;
            }
            low--;
            r--;
            c++;
            while(r>=high)
            {
                // cout<<r<<" "<<c<<" "<<ptr->val<<endl;
                mat[r][c]=val++;
                r--;
            }
            left++;
            r++;
            c++;
        }

        return mat; 
    }
};