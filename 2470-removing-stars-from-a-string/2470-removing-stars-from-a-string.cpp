class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto c: s)
        {
            if(c=='*')
                st.pop();
            else
                st.push(c);
        }

        s="";
        while(st.size())
        {
            s=st.top()+s;
            st.pop();
        }

        return s;
    }
};