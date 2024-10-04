class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(), skill.end());

        long long sum=0;
        for(auto i: skill)
            sum+=i;
        // if(sum%2)
        //     return -1;

        int teams=n/2;
        if(sum%teams)
            return -1;

        int tsum=sum/teams;

        // cout<<teams<<" "<<tsum<<endl;
        int left=0, right=n-1;
        long long ans=0;
        while(left<right)
        {
            if(skill[left]+skill[right]!=tsum)
                return -1;
            ans+=(skill[left++]*skill[right--]);
        }
        return ans;
    }
};