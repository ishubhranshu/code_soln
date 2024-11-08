class Solution {
public:
    string solve(string s)
    {
        string ns="";
        char c=s[0];
        int count=1;

        for(int i=1; i<s.length(); i++)
        {
            if(s[i]!=c)
            {
                ns+=to_string(count);
                ns+=c;

                count=1;
                c=s[i];
            }
            else
                count++;
        }
        ns+=to_string(count);
        ns+=c;

        return ns;
    }
    string countAndSay(int n) {
        string s="1";
        for(int i=0; i<n-1; i++)
            s=solve(s);

        return s;
    }
};