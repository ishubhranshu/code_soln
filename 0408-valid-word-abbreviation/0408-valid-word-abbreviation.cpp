class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n=word.length();
        int m=abbr.length();
        if(m>n)
            return false;

        int i=0;
        int j=0;

        while(i<n && j<m)
        {
            if(abbr[j]>= 'a' && abbr[j]<= 'z')
            {
                if(abbr[j]!=word[i])
                    return false;
                i++;
                j++;
            }
            else if(abbr[j]=='0')
                return false;
            else
            {
                int num=0;
                while(j<m && !(abbr[j]>= 'a' && abbr[j]<= 'z'))
                {
                    num=num*10+(abbr[j]-'0');
                    j++;
                }
                if(j>=m)
                {
                    if(n-i == num)
                        return true;
                    return false;
                }
                else
                    i+=num;
            }
        }

        return i==n && j==m;
    }
};