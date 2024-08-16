class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans=INT_MIN, right=arrays[0].back(), left=arrays[0][0];
        
        for(auto arr: arrays)
        {
            ans=max(ans,max(abs(arr.back()-left), abs(right-arr[0])));
            right=max(right, arr.back());
            left=min(left, arr[0]);
        }

        return ans;
    }
};