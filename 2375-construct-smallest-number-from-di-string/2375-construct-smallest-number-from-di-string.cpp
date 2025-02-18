class Solution {
public:
    bool solve(int ind, string &pattern, int &bitMask, string &s)
    {
        // cout<<s<<" "<<bitMask<<endl;
        if(ind==pattern.size())
            return true;

        for(int i=0; i<9; i++)
        {
            if((bitMask & (1<<i)) != 0)
                continue;
            if(pattern[ind]=='I' && s.back() >= ('1'+i))
                continue;
            if(pattern[ind]=='D' && s.back() <= ('1'+i))
                continue;

            s.push_back('1'+i);
            bitMask= bitMask | (1<<i);
            if(solve(ind+1, pattern, bitMask, s))
                return true;
            s.pop_back();
            bitMask=bitMask &  ~(1<<i);
        }
        return false;
    }
    string smallestNumber(string pattern) {
        string s="";
        int bitMask=0;
        for(int i=0; i<9; i++)
        {
            s.push_back('1'+i);
            bitMask= bitMask | (1<<i);
            if(solve(0, pattern, bitMask, s))
                return s;
            s.pop_back();
            bitMask=bitMask &  ~(1<<i);
        }
        return "";
    }
};