class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);

        for(auto c: s)
            freq[c-'a']++;
        
        int ans=0;

        for(auto f: freq)
        {
            cout<<f<<" ";
            if(f<3)
            {
                // cout<<f<<endl;
                ans+=f;
            }
            else if(f%2)
            {
                // cout<<1<<endl;
                ans+=1;
            }
            else
            {
                // cout<<2<<endl;
                ans+=2;
            }
            // cout<<f<<" "<<f%3<<endl;
            // ans+=f%3;
        }

        return ans;
    }
};