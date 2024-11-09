class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long ans=x;
        int i=0;

        while(n)
        {
            while(ans & (1LL << i))
                i++;
            // cout<<i<<" "<<(n & 1)<<endl; 
            if(n&1)
                ans=ans | (1LL << i);
            n=(n>>1);
            i++;
        }
        return ans;
    }
};