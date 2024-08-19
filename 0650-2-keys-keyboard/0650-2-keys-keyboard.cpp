class Solution {
public:
    int solve(int c, int p, int n)
    {
        if(c+p==n)
            return 0;
        if(c+p>n)
            return 2000;

        return min(1+solve(c+p, p, n), 2+solve(c+c, c, n));
    }
    int minSteps(int n) {
        if(n==1)
            return 0;
        return 2+solve(1, 1, n);
    }
};