class Solution {
public:
    char solve(char c, int val)
    {
        val=val%26;
        int ascii=c;
        cout<<ascii<<" "<<val<<" ";
        ascii+=val;

        if(ascii>='z')
            ascii=ascii%('z'+1);
        if(ascii<'a')
        {
            int temp='a'-ascii;
            ascii='z'-temp;
        }

        cout<<ascii<<endl;
        return ascii;

    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length(), m=shifts.size();
        vector<int> diff(n, 0);

        for(auto shift: shifts)
        {
            int left=shift[0];
            int right=shift[1];
            int sh=shift[2]==0 ? -1:1;

            diff[left]+=sh;
            if(right!=n-1)
                diff[right+1]-=sh;

            
        }

        int sh=0;

        for(int i=0; i<n; i++)
        {
            sh+=diff[i];
            int tempdiff=sh%26;
            // cout<<i<<" "<<tempdiff<<" "<<(((tempdiff+26)+s[i]-'a')%26)<<endl;
            s[i]=(((tempdiff+26)+s[i]-'a')%26)+'a';
        }

        return s;
    }
};