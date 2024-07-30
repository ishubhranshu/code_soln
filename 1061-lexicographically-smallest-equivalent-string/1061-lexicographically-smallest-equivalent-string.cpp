class Solution {
public:
    class UnionSet{
        public:
            vector<int> par;
            vector<int> siz;
            UnionSet(int n)
            {
                par.resize(n);
                siz.resize(n, 1);
                for(int i=0; i<n; i++)
                    par[i]=i;
            }

            int upar(int a)
            {
                if(a==par[a])
                    return a;
                
                return par[a]=upar(par[a]);
            }

            void join(int a, int b)
            {
                int upa=upar(a);
                int upb=upar(b);

                if(upa==upb)
                    return;
                if(siz[upa]>=siz[upb])
                {
                    siz[upa]+=siz[upb];
                    par[upb]=upa;
                }
                else
                {
                    siz[upb]+=siz[upa];
                    par[upa]=upb;
                }
            }
        unordered_map<char, vector<char>> grp()
        {
            unordered_map<char, vector<char>> mp;
            for(int i=0; i<26; i++)
                mp['a'+upar(i)].push_back('a'+i);
    
            for(auto i: mp)
                sort(mp[i.first].begin(), mp[i.first].end());

            return mp;
        }
    };
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        UnionSet us(26);
        
        for(int i=0; i<s1.length(); i++)
            us.join(s1[i]-'a', s2[i]-'a');

        unordered_map<char, vector<char>> mp=us.grp();

        for(auto i: mp)
        {
            cout<<i.first<<"->";
            for(auto j: i.second)
                cout<<j<<" ";
            cout<<endl;
        }

        for(int i=0; i<baseStr.size(); i++)
        {
            char p=us.upar(baseStr[i]-'a')+'a';

            baseStr[i]=mp[p][0];
        }

        return baseStr;
        
    }
};