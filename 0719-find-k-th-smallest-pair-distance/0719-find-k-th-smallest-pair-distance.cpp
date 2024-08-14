class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort((nums.begin()), (nums.end()));
        int l=0, r=nums.back()-nums[0];
        int ans=-1;
        while(l<=r)
        {
            int mid=(r+l)/2;
            int i=0, j=1;
            int count=0;
            // cout<<"l: "<<l<<" "<<"r: "<<r<<endl;
            // cout<<"mid: "<<mid<<endl;

            while(j<nums.size())
            {
                while(nums[j]-nums[i]>mid)
                    i++;
                count+=(j-i);
                j++;    
            }

            if(k<=count)
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
            // cout<<k<<" "<<count<<endl;
            // break;
        }
        // cout<<"==="<<l<<' '<<r<<endl;

        return ans;
    }
};