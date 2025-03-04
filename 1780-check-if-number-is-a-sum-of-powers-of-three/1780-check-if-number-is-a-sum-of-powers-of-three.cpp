class Solution {
public:
    bool checkPowersOfThree(int n) {
        int lastPower=1;
        while(pow(3, lastPower) < n)
            lastPower++;

        while(n)
        {
            while(pow(3, lastPower) > n)
                lastPower--;
            n-=pow(3, lastPower);
            if(n>=pow(3, lastPower))
                return false;
            lastPower--;
        }

        return true;
    }
};