class Solution {
public:
    char findKthBit(int n, int k) {
        if(k==1)
            return '0';
        string s="0";
        n--;
        while(n--)
        {
            string temp=s;
            string inv="";
            for(int i=temp.length()-1; i>=0; i--)
            {
                if(temp[i]=='1')
                    inv+='0';
                else
                    inv+='1';
            }
            s=temp+'1'+inv;
            // cout<<s<<endl;
            if(s.length()>=k)
                return s[k-1];
        }

        return ' ';
    }
};