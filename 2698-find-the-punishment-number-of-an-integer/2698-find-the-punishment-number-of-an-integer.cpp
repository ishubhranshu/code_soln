class Solution {
public:
    bool  check(string s, int n)
    {
        if(s=="" && n==0)   
            return 1;
        if(n<0)
            return 0;

        for(int i=0; i<s.size(); i++)
        {
            string left=s.substr(0, i+1);
            string right=s.substr(i+1);
            int l=stoi(left);
            if(check(right, n-l))
                return 1;
        }

        return 0;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            int sq=i*i;
            if(check(to_string(sq), i))
                ans+=sq;
        }

        return ans;
    }
};