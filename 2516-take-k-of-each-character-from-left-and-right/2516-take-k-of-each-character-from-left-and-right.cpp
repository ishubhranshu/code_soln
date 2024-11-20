class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0)
            return 0;
        unordered_map<char, int> ump;
        int left=0, right=0, n=s.length();
        int ans=n+1;
        for(auto c: s)
            ump[c]++;

        while(right<n)
        {
            // cout<<left<<" "<<right<<" "<<ump['a']<<" "<<ump['b']<<" "<<ump['c']<<" "<<n-(right-left)<<endl;
            if(ump['a']>=k && ump['b']>=k && ump['c']>=k)
            {
                ans=min(ans, n-(right-left));
                ump[s[right]]--;
                right++;
                if(ump['a']>=k && ump['b']>=k && ump['c']>=k)
                    ans=min(ans, n-(right-left));
            }
            else if(left<n)
            {
                ump[s[left]]++;
                left++;
            }
            else
                break;
        }
        if(ans>n)
            return -1;
        
        return ans;
    }
};