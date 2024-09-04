class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> st;
        for(auto i: obstacles)
            st.insert({i[0], i[1]});
        // if(st.find({0, 0})!=st.end())
        //     return 0;
        int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x=0, y=0, ans=0, d=0;

        for(auto i: commands)
        {
            cout<<d<<" "<<x<<" "<<y<<" "<<i<<endl;
            if(i==-1)
                d=(d+1)%4;
            else if(i==-2)
                d=abs((d+3)%4);
            else
            {
                int dx=dir[d][0], dy=dir[d][1];
                
                for(int ind=0; ind<i; ind++)
                {
                    int nx=x+dx, ny=y+dy;
                    if(st.find({nx, ny})!=st.end())
                        break;
                    x+=dx;
                    y+=dy;
                }
            }
            ans=max(ans, x*x+y*y);
        }

        return ans;
    }
};