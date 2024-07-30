class Solution {
public:
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans(s.length(), 0);
        for(int i=0; i<s.length(); i++)
        {
            int x=startPos[0], y=startPos[1];
            int count=0;
            for(int j=i; j<s.length(); j++)
            {
                if(s[j]=='R') y++;                        
                else if(s[j]=='L')  y--;
                else if(s[j]=='U')  x--;
                else if(s[j]=='D')  x++;
                
                if(x>=n || y>=n || x<0 || y<0)
                    break;
                count++;
            }
            ans[i]=count;
        }

        return ans;
    }
};