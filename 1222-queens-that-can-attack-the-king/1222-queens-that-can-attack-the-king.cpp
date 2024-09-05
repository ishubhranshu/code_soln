class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int dirx[] = {1,-1,1,-1,0,1,0,-1};
        int diry[] = {1,-1,-1,1,1,0,-1,0};
        set<pair<int, int>> st;
        for(auto i: queens)
            st.insert({i[0], i[1]});
        vector<vector<int>> ans;
        for(int i=0; i<8; i++)
        {
            int x=king[0], y=king[1];
            while(1)
            {
                x=x+dirx[i];
                y=y+diry[i];
                if(x<0 || y<0 || x==8 || y==8)
                    break;
                if(st.find({x, y})!=st.end())
                {
                    ans.push_back({x, y});
                    break;
                }
            }
        }

        return ans;
    }
};