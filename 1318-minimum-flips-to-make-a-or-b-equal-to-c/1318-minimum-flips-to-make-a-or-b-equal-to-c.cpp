class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0; i<31; i++)
        {
            int abit=(1<<i)&a;
            int bbit=(1<<i)&b;
            int cbit=(1<<i)&c;
            
            // cout<<i<<" "<<cbit<<" "<<bbit<<" "<<abit<<endl;
            if(cbit)
            {
                if(!abit && !bbit)
                    ans++;
            }

            else
            {
                if(abit)
                    ans++;
                if(bbit)
                    ans++;
                
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};