class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int ans=INT_MAX;
        int left=1, right=1;
        for(auto q: quantities)
            right=max(right, q);
        while(left<=right)
        {
            int mid=((left+right)/2);
            int tempans=0;
            for(int q: quantities)
                tempans+=ceil((float)q/mid);

            // cout<<left<<" "<<right<<" "<<mid<<" "<<tempans<<endl;
            if(tempans>n)
            {
                left=mid+1;
            }
            else
            {
                ans=min(ans, mid);
                right=mid-1;
            }
        }
        return ans;
    }
};