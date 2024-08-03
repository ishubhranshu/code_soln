class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {
        sort(t.begin(), t.end());
        sort(a.begin(), a.end());
        
        for(int i=0; i<t.size(); i++)
            if(t[i]!=a[i])
                return 0;
        return 1;
    }
};