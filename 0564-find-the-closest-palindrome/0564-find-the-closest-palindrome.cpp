class Solution {
public:
    long f(long fh, bool e)
    {
        long res=fh;

        if(!e)
            fh/=10;

        while(fh)
        {
            res=res*10+fh%10;
            fh/=10;
        }

        return res;
    }
    string nearestPalindromic(string s) {
        
        int n = s.length();
        int mid = n/2;
        int firstHalfLen = n%2==0 ? mid : mid+1;
        long firstHalf = stol(s.substr(0, firstHalfLen));

        vector<long> ress;

        ress.push_back(f(firstHalf, n%2==0));
        ress.push_back(f(firstHalf+1, n%2==0));
        ress.push_back(f(firstHalf-1, n%2==0));
        ress.push_back((long)pow(10,n)+1);
        ress.push_back((long)pow(10,n-1)-1);

        long diff = LONG_MAX;
        long result = INT_MAX;
        long orig = stol(s);

        for(long num: ress)
        {
            if(num==orig)   continue;
            if(abs(num-orig) < diff)
            {
                diff = abs(abs(num)-orig);
                result=num;
            }
            else if(abs(num-orig) == diff)
                result=min(result, num);
        }

        return to_string(result);
    }
};