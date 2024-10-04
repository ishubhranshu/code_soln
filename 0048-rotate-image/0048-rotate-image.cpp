class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n= a.size(), m=a[0].size();
        int left=0,up=0,down=n-1,right=m-1;
        while(left<right && up<down)
        {
            for(int i=0; i<right-left; i++)
            {
                int temp=a[up][left+i];
                a[up][left+i]=a[down-i][left];
                a[down-i][left]=a[down][right-i];
                a[down][right-i]=a[up+i][right];
                a[up+i][right]=temp;
            }
            left++;
            right--;
            up++;
            down--;
        }
    }
};