class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();

        if(n%2)
            return 0;
        
        int open=0;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='(' || locked[i]=='0')
                open++;
            else
                open--;

            if(open<0)
                return 0;
        }

        open=0;
        
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]==')' || locked[i]=='0')
                open++;
            else
                open--;
            if(open<0)
                return 0;
        }

        return 1;
    }
};