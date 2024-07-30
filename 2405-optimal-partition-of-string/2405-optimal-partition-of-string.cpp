class Solution {
public:
    int partitionString(string s) {
        int n=s.length();
        int ans=1;
        int freq=0;
        for(int i=0; i<n; i++)
        {
            int pos=1<<(s[i]-'a');
            // cout<<pos<<" "<<freq<<endl;
            if((freq&pos)!=0)
            {
                ans++;
                freq=0;
            }
            freq=pos|freq;
        }

        return ans;
    }
};