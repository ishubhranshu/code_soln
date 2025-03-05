class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)
            return 1;

        n--;

        return 1+4*((1LL*n*(n+1))/2);
    }
};