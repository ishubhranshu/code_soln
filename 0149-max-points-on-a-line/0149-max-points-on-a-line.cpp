class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2)
            return n;
        int ans=1;
        
        for(int i=0; i<n; i++)
        {
            unordered_map<string, int> mp;
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                int dy=points[j][1]-points[i][1];
                int dx=points[j][0]-points[i][0];

                if(dx==0)
                    mp["inf"]++;

                else if(dy/dx<0)
                {
                    dx=abs(dx);
                    if(dy>0)
                        dy*=-1;
                    int gcd=__gcd(abs(dy), abs(dx));
                    dy/=gcd;
                    dx/=gcd;
                }
                else
                {
                    int gcd=__gcd(abs(dy), abs(dx));
                    dy/=gcd;
                    dx/=gcd;
                }
                
                mp[to_string(dy) + ":" + to_string(dx)]++;
            }
            for(auto ii: mp)
            {   
                ans=max(ii.second, ans);
                // cout<<i<<" "<<ii.first<<" "<<ii.second<<endl;
            }
        }
        cout<<ans;
        return ans+1;
    }
};