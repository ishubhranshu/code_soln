class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> ump;
        for(auto i: arr)
            ump[i]++;

        for(auto i: ump)
            if((i.first==0 && ump[0]>=2) || (i.first!=0 && ump.find(2*i.first)!=ump.end()))    return 1;

        return 0;
    }
};