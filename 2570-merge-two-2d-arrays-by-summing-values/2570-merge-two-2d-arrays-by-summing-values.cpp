class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        int ID=0;
        int VAL=1;
        vector<vector<int>> mergedNums;
        while(i<n && j<m)
        {
            if(nums1[i][ID]<nums2[j][ID])
                mergedNums.push_back(nums1[i++]);

            else if(nums1[i][ID]>nums2[j][ID])
                mergedNums.push_back(nums2[j++]);
            else
                nums1[i][VAL]+=nums2[j++][VAL];
        }

        while(i<n)
            mergedNums.push_back(nums1[i++]);

        while(j<m)
            mergedNums.push_back(nums2[j++]);

        return mergedNums;

    }
};