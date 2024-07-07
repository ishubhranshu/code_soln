class Solution {
public:
    int numWaterBottles(int n, int m) {
        return n+(n-1)/(m-1);
    }
};