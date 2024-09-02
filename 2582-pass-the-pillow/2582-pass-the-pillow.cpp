class Solution {
public:
    int passThePillow(int n, int time) {


        time%=(2*(n-1));
        if(n==time)
            return n-1;
        
        if(time>n)
            return n-(time%n+1);

        return time+1;

    }
};