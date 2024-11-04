class Solution {
public:
    string compressedString(string word) {
        char c=word[0];
        int count=1;
        int n=word.size();
        string ans="";
        for(int i=1; i<n; i++)
        {
            if(count==9 || c!=word[i])
            {
                char cc=('0'+count);
                // cout<<cc<<endl;
                string s="";
                s+=cc;
                s+=c;
                ans+=s;
                count=1;
                c=word[i];
            }
            else
                count++;
        }
        char cc=('0'+count);
        // cout<<cc<<endl;
        string s="";
        s+=cc;
        s+=c;
        ans+=s;
        

        return ans;
    }
};