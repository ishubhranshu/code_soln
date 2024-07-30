class Solution {
public:
    int minimumDeletions(string s) {
        int acount=0, bcount=0;
        for(auto i: s)
        {
            if(i=='a')
                acount++;
        }

        int ind=0, ans=INT_MAX;
        while(ind<s.length())
        {
    
            if(s[ind]=='a')
                acount--;
            
            ans=min(ans, acount+bcount);
            // cout<<acount<<" "<<bcount<<endl;
            if(s[ind]=='b')
                bcount++;

            ind++;
        }

        return ans;
    }
};