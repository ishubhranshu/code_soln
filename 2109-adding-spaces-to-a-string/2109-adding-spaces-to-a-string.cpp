class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int offset=0;
        for(int i=0; i<spaces.size(); i++)
            spaces[i]+=(offset++);

        s.resize(s.length()+spaces.size());
        

        int diff=spaces.size();
        int ind=spaces.size()-1;
        int i=s.length()-1;
        
        while(i-diff>=0 && ind>=0)
        {
            // cout<<i<<endl;
            if(i==spaces[ind])
            {
                // cout<<i<<endl;
                s[i]=' ';
                ind--;
                diff--;
            }
            else
            {
                s[i]=s[i-diff];
            }
            i--;
        }
        if(ind==0)
            s[0]=' ';
        return s;
    }
};