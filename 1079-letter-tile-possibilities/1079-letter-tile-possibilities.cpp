class Solution {
public:
    int count=0;
    unordered_set<string> ans;
    void solve(string &tiles, vector<bool> &used, string &s)
    {
        int n=tiles.size();
        ans.insert(s);
        for(int i=0; i<n; i++)
        {
            if(used[i]==true)
                continue;
            used[i]=true;
            s.push_back(tiles[i]);
            solve(tiles, used, s);
            used[i]=false;
            s.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {  
        int n=tiles.size();
        string s="";
        vector<bool> used(n, false);
        solve(tiles, used, s);

        return ans.size()-1;  
    }
};