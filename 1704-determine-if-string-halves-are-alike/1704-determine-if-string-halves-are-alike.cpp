class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(!(s[i]=='a' || s[i]=='u' || s[i]=='o' || s[i]=='i' || s[i]=='e' || 
                s[i]=='A' || s[i]=='U' || s[i]=='O' || s[i]=='I' || s[i]=='E'))
                continue;
            if(i<n/2)
                count++;
            else
                count--;
        }
        cout<<count;
        return !count;
    }
};