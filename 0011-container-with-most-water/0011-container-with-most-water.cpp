class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1, ans=0;
        while(l<r)
        {
            int h=min(height[l], height[r]);
            int w=r-l;
            // cout<<w*h<<endl;
            ans=max(ans, h*w);
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};