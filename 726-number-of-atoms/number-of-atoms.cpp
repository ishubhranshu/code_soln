class Solution {
public:
    int sti(string &s)
    {
        if(s.empty())
            return 1;
        int i=0;
        for(auto c: s)
            i=i*10+(c-'0');
        return i;
    }
    string countOfAtoms(string f) {
        // f='('+f+;
        stack<map<string, int>> st;
        st.push(map<string, int>());
        int i=0, n=f.length();

        while(i<n)
        {
            if(f[i]=='(')
            {
                st.push(map<string, int>());
                i++;
            }
            else if(f[i]==')')
            {
                map<string, int> c_fs = st.top();
                st.pop();
                i++;
                string mltplr;
                while(i<n && isdigit(f[i]))
                    mltplr+=f[i++];
                
                int mul = sti(mltplr);
                for(auto &i: c_fs)
                    c_fs[i.first]*=mul;

                for(auto &i: c_fs)
                    st.top()[i.first]+=i.second;
            }
            else
            {
                string c_f;
                c_f += (f[i++]);
                while(i<n && islower(f[i]))
                    c_f+=f[i++];
                
                string c_c="";
                while(i<n && isdigit(f[i]))
                    c_c+=f[i++];

                int c_cd=sti(c_c);

                // cout<<typeid(c_cd).name()<<endl;
                st.top()[c_f]+=c_cd;
            }
        }

        string ans="";
        for(auto i: st.top())
            if(i.second)
                ans+=i.first+(i.second>1 ? to_string(i.second) : "");
            // cout<<i.first<<" "<<i.second<<endl;
        // cout<<st.size();
        return ans;
    }
};