class Solution {
public:
    string makeFancyString(string s) {
        int count=0;
        char lastc='-';
        string ans="";
        for(auto c: s)
        {
            if(lastc!=c)
            {
                count=1;
                lastc=c;
                ans+=c;
            }
            else
            {
                if(count!=2)
                {
                    count++;
                    ans+=lastc;
                }
            }
        }
        return ans;
    }
};