class Solution {
public:
    int numberOfChild(int n, int time) {
        time%=(2*(n-1));
        if(n==time)
            return n-2;
        
        if(time>n)
            return n-(time%n+1)-1;

        return time;
    }
};