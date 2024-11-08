class Solution {
public:
    int compress(vector<char>& chars) {
        int counts=1;
        char c=chars[0];
        int n=chars.size();
        string s="";
        for(int i=1; i<n; i++)
        {
            if(chars[i]!=c)
            {
                if(counts==1)
                {
                    s+=c;
                }
                else
                {
                    string scount=to_string(counts);
                    s+=c;
                    s+=scount;
                }
                counts=1;
                c=chars[i];
            }
            else
                counts++;
        }
        if(counts==1)
        {
            s+=c;
        }
        else
        {
            string scount=to_string(counts);
            s+=c;
            s+=scount;
        }

        // cout<<s;
        // chars.resize(s.length());
        for(int i=0; i<s.length(); i++)
            chars[i]=s[i];

        return s.length();
    }
};