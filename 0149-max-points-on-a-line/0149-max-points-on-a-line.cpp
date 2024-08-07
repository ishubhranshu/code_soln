class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=1;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int cp=2;
                int dy=points[j][1]-points[i][1];
                int dx=points[j][0]-points[i][0];
                for(int k=0; k<n; k++)
                {
                    if(k==i || k==j)
                        continue;
                    int dyy=points[k][1]-points[i][1];
                    int dxx=points[k][0]-points[i][0];
                    
                    if(dyy*dx == dxx*dy)
                        cp++;
                }
                ans=max(ans, cp);
            }
        }
        return ans;
    }
};