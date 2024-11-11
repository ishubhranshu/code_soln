class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> primes(1001, 1);
        primes[1]=0;
        primes[0]=0;

        for(int i=2; i<1001; i++)
        {
            if(primes[i])
            {
                int j=i+i;
                while(j<1001)
                {
                    primes[j]=0;
                    j+=i;
                }
            }
        }
        // for(int i=0; i<100; i++)
        //     if(primes[i])
        //         cout<<i<<" "<<primes[i]<<endl;

        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            int pprm=nums[i]-1;
            
            if(i==0)
            {
                while(pprm>0 && !primes[pprm])
                    pprm--;
            }
            else
            {
                while(pprm>0 && (!primes[pprm] || nums[i]-pprm<=nums[i-1]))
                    pprm--;
            }
            // cout<<nums[i]<<" "<<pprm<<" "<<nums[i]-pprm<<endl;
            nums[i]-=pprm;
        }

        for(int i=0; i<n-1; i++)
            if(nums[i]>=nums[i+1])
                return 0;

        return 1;
    }
};