class Solution {
public:
    string shortestPalindrome(string s) {
        string r=s;
        int n=s.length();
        reverse(r.begin(), r.end());
        int i=0;
        
        while(i<n)
        {
            // cout<<i<<" "<<memcmp(s.c_str(), r.c_str()+i, n-i)<<endl;
            if(memcmp(s.c_str(), r.c_str()+i, n-i)==0)
                return r.substr(0, i) + s;
            i++;
        }
        return r+s;
    }
};