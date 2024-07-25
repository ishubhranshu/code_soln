class Solution {
public:
    void merge(int l, int mid, int r, vector<int>& nums)
    {
        int LFT=mid-l+1;
        int RGT=r-mid;

        vector<int> left, right;
        for(int i=l; i<=mid; i++)
            left.push_back(nums[i]);
        for(int i=mid+1; i<=r; i++)
            right.push_back(nums[i]);

        int i=0, j=0, k=l;
        while(i<LFT && j<RGT)
        {
            if(left[i]>right[j])
                nums[k++]=right[j++];
            else
                nums[k++]=left[i++];
        }
        while(i<LFT)
            nums[k++]=left[i++];
        while(j<RGT)
            nums[k++]=right[j++];
        
    }
    void mergesort(int l, int r, vector<int>& nums)
    {
        if(l>=r)
            return;

        int mid=(l+r)/2;
        mergesort(l, mid, nums);
        mergesort(mid+1, r, nums);
        merge(l, mid, r, nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(0, n-1, nums);
        return nums;
    }
};