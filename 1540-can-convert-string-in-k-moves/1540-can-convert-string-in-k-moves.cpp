class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n=s.length(), m=t.length();
        if(n!=m)
            return 0;
        int maxi=0;
        unordered_map<int, int> used;
        for(int i=0; i<n; i++)
        {
            int req=(t[i]-s[i]+26)%26;

            if(req==0)
                continue;

            if(used.count(req))
            {
                used[req]+=26;
                maxi=max(maxi, used[req]);
            }
            else
            {
                used[req]=req;
                maxi=max(maxi, used[req]);
            }
            // cout<<s[i]<<" "<<t[i]<<" "<<used[req]<<endl;
            if(maxi>k) return 0;
        }

        return 1;
    }
};