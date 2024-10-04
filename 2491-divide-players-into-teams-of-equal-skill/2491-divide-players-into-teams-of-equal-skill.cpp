class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        vector<int> freq(1001, 0);
        
        long long sum=0;
        for(auto i: skill)
        {
            sum+=i;   
            freq[i]++;
        }

        int teams=n/2;
        if(sum%teams)
            return -1;

        int tsum=sum/teams;
        long long ans=0;
        for(int i=0; i<1001; i++)
        {
            if(freq[i]==0)
                continue;
            while(freq[i])
            {
                if(freq[tsum-i]==0)
                    return -1;

                ans+=(i*(tsum-i));
                freq[i]--;
                freq[tsum-i]--;
            }    
        }
        return ans;
    }
};