class Solution {
public:
    long long count(long long left, long long right, long long n)
    {
        long long ccount=0;
        while(left<=n)
        {
            ccount+=(right-left);
            left*=10;
            right=min(right*10, n+1);
        }
        return ccount;
    }
    int findKthNumber(int n, int k) {
        long long left=1;
        k--;
        while(k>0)
        {
            long long ccount=count(left, left+1, n);
            if(ccount<=k)
            {
                k-=ccount;
                left++;
            }
            else
            {
                k-=1;
                left*=10;
            }
        }

        return left;
    }
};