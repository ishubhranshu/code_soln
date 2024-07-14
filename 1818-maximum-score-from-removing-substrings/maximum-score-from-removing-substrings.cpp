class Solution {
public:
    int solve(string &s, char a, char b, int pt)
    {
        stack<char> st;
        int pts=0;
        for(auto c: s)
        {
            if(st.size()!=0 && st.top()==a && c==b)
            {
                st.pop();
                pts+=pt;
            }
            else
                st.push(c);
        }
        s="";
        while(st.size())
        {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return pts;
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;

        if(x>y)
        {
            ans+=solve(s, 'a', 'b', x);
            // cout<<s<<endl;
            ans+=solve(s, 'b', 'a', y);
        }
        else
        {
            ans+=solve(s, 'b', 'a', y);
            // cout<<s<<endl;
            ans+=solve(s, 'a', 'b', x);
            // cout<<s<<endl;
        }

        return ans;
    }
};