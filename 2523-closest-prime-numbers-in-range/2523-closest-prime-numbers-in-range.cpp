class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> nums(right+1, true);

        for(int i=2; i<=right; i++)
        {
            if(nums[i]==true)
            {
                int mul=2;
                while(mul*i<=right)
                {
                    nums[mul++*i]=false;
                }
            }
        }
    
        // for(int i=0; i<=right; i++)
        //     cout<<i<<" "<<nums[i]<<endl;
        int last=-1;
        int minDiff=INT_MAX;
        vector<int> ans={-1, -1};

        for(int i=max(left,2); i<=right; i++)
        {
            // cout<<nums[i]<<" ";
            if(nums[i]==true)
            {
                if(last!=-1)
                {
                    int curr=i;
                    // cout<<curr-last<<endl;
                    if(minDiff>curr-last)
                    {
                        minDiff=curr-last;
                        ans={last, curr};

                    }
                }
                last=i;
            }
        }

        return ans;
    }
};