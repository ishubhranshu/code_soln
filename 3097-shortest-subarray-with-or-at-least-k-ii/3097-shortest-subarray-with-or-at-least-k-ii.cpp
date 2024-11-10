class Solution {
public:
    void remove(int l, vector<int> &bits, int &ror)
    {
        int i=0;
        while(l)
        {
            if(l & 1)
            {
                bits[i]--;
                if(!bits[i])
                    ror=ror & ~(1<<i);
            }
            l=l>>1;
            i++;
        }
    }
    void add(int r, vector<int> &bits, int &ror)
    {
        int i=0;
        while(r)
        {
            if(r & 1)
            {
                bits[i]++;
                if(bits[i]==1)
                    ror=ror | (1<<i);
            }
            r=r>>1;
            i++;
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        vector<int> bits(32, 0);
        int l=0, r=0;
        int n=nums.size();
        int ror=0;
        int ans=INT_MAX;
        while(r<n)
        {
            add(nums[r++], bits, ror);
            // cout<<"     "<<" "<<l<<" "<<r<<" "<<ror<<endl;
            while(l<r && ror>=k)
            {
                ans=min(ans, r-l);
                // cout<<l<<" "<<r<<" "<<ror<<endl;
                remove(nums[l++], bits, ror);
            }
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};