class Solution {
public:
    int countbits(int n)
    {
        int bits=0;
        while(n)
        {
            bits+=1 & n;
            n=n>>1;
        }

        return bits;
    }
    int minimizeXor(int num1, int num2) {
        int b1=countbits(num1);
        int b2=countbits(num2);
        int ans;
        if(b1==b2)
            return ans=num1;
        
        if(b1>b2)
        {
            ans=num1;
            int i=0;
            while(b1>b2 && i<32)
            {
                if((1<<i) & num1)
                {
                    b1--;
                    ans=ans & ~(1<<i);
                }
                i++;
            }
            return ans;
        }

        ans=num1;
        int i=0;
        while((b1<b2 && i<32))
        {
            if(!((1<<i) & num1))
            {
                b2--;
                ans=ans | (1<<i);
            }
            i++;
        }
        return ans;
    }
};