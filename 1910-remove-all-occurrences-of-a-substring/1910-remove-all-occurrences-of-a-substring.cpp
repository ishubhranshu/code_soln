class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m=part.length();
        int i=0;
        
        while(i<s.length())
        {
            if(i>=m-1)
            {
                int ind=i-(m-1);
                string cstr=s.substr(ind, m);
                if(cstr==part)
                {
                    cout<<ind<<" "<<i<<endl;
                    string lstr="", rstr="";
                    if(ind!=0)
                        lstr=s.substr(0, ind);
                    if(i!=s.length()-1)
                        rstr=s.substr(i+1);
                    cout<<lstr+rstr<<endl;
                    s=lstr+rstr;
                    i=i-m;
                }
            }
            i++;
        }

        return s;
    }
};