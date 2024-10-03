class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0, right=n-1;
        int leftmax=0, rightmax=0;
        int ans=0;
        while(left<right)
        {
            if(height[left]<height[right])
            {
                leftmax=max(leftmax, height[left]);
                ans+=(leftmax-height[left++]);
            }
            else
            {
                rightmax=max(rightmax, height[right]);
                ans+=(rightmax-height[right--]);
            }
        }
        return ans;
    }
};