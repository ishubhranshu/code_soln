class Solution {
public:
    int solve(string &s, string c, int pt)
    {
        int i=0, j=0;
        int occ=0;
        while(j<=s.length())
        {
            if(i>=2 && s.substr(i-2, 2)==c)
            {
                occ++;
                i-=2;
            }
            s[i]=s[j];
            i++;j++;
        }
        s=s.substr(0, s.length()-2*occ);
        return pt*occ;
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;

        if(x>y)
        {
            ans+=solve(s, "ab", x);
            cout<<s<<endl;
            ans+=solve(s, "ba", y);
            cout<<s<<endl;
        }
        else
        {
            ans+=solve(s, "ba", y);
            cout<<s<<endl;
            ans+=solve(s, "ab", x);
            cout<<s<<endl;
        }

        return ans;
    }
};