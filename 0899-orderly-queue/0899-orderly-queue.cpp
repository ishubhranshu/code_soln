class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1)
        {
            sort(s.begin(), s.end());
            return s;
        }

        string ans=s;
        s=s+s;
        for(int i=0; i<ans.length(); i++)
        {
            string r=s.substr(i, ans.length());
            if(ans>r)
                ans=r;
        }

        return ans;
    }
};