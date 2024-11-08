class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int ind=0, count=1;
        char c=chars[0];
        
        for(int i=1; i<n; i++)
        {
            if(chars[i]!=c)
            {
                if(count==1)
                    chars[ind++]=c;
                else
                {
                    chars[ind]=c;
                    ind++;
                    string scount=to_string(count);
                    for(auto sc: scount)
                        chars[ind++]=sc;
                }
                count=1;
                c=chars[i];
            }
            else
                count++;
            // cout<<count<<endl;
        }
        if(count==1)
            chars[ind++]=c;
        else
        {
            chars[ind]=c;
            ind++;
            string scount=to_string(count);
            for(auto sc: scount)
                chars[ind++]=sc;
        }


        return ind;
    }
};