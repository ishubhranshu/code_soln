class Solution {
public: 
    vector<string> ans;
    
    bool check(string &s)
    {
        if(s.length()!=1 && s[0]=='0')
            return 0;

        return stoi(s)<=255;
    }
    
    void solve(int ind, string &s, int dots, string &ip)
    {
        // cout<<ip<<endl;
        if(ind==s.length() && dots==0)
        {
            ans.push_back(ip.substr(0, ip.length()-1));
            return;
        }
        if(dots==0 || ind==s.length())
            return;

        for(int i=0; i<3; i++)
        {
            if (ind + i + 1 > s.length()) 
                break;
            string test=s.substr(ind, i+1);
            if(!check(test))
                continue;
            // cout<<test<<endl;
            ip+=test;
            ip+='.';
            solve(ind+i+1, s, dots-1, ip);
            ip.resize(ip.size()-1-test.size());
        }


    }
    vector<string> restoreIpAddresses(string s) {
        string ip="";
        solve(0, s, 4, ip);

        return ans;
    }
};