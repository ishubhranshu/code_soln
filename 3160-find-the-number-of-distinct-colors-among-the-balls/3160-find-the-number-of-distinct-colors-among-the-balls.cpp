class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> clrToBall, ballToClr;
        vector<int> ans;

        for(auto &q: queries)
        {
            int currBall=q[0];
            int toClr=q[1];

            if(ballToClr.find(currBall) != ballToClr.end())
            {
                int prevClr=ballToClr[currBall];

                clrToBall[prevClr]--;

                if(clrToBall[prevClr]==0)
                    clrToBall.erase(prevClr);
            }
            
            ballToClr[currBall]=toClr;
            clrToBall[toClr]++;

            
            ans.push_back(clrToBall.size());
        }

        return ans;
        
    }
};