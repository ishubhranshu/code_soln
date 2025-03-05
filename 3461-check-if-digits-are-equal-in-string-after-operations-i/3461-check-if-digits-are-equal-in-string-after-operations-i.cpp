class Solution {
public:
    bool hasSameDigits(string s) {

        while(s.length()>2)
        {
            int n=s.length();
            string ns="";
            for(int i=0; i+1<n; i++)
            {
                int d1=s[i]-'0';
                int d2=s[i+1]-'0';
                int sum=(d1+d2)%10;
                ns.push_back('0'+sum);
            }
            s=ns;
            // cout<<s<<endl;
        }

        return s[0]==s[1];

    }
};