class Solution {
public:
    bool check(vector<int>& ranks, int cars, long long timeLimit)
    {
        for(auto r: ranks)
        {
            long long repairable=sqrt(timeLimit/r);
            cars-=repairable;
            if(cars<=0)
                return true;
        }

        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long right=LONG_MAX;
        long long left=1;
        long long minTime=LONG_MAX;
        
        while(left<=right)
        {
            long long mid=left+(right-left)/2;

            bool possible=check(ranks, cars, mid);

            if(possible)
            {
                minTime=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }

        return minTime;
    }
};