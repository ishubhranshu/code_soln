class Solution {
public:
    int numWaterBottles(int n, int m) {
        int drink=0;
        int empty=0;
        while((n+empty)>=m)
        {
            drink+=n;
            empty+=n;
            n=empty/m;
            empty=empty%m;
            cout<<drink<<endl;
        }
        drink+=n;
        return drink;
    }
};