class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy=arr;
        unordered_map<int, int> ump;
        sort(copy.begin(), copy.end());
        int r=1;
        for(auto i: copy)
            if(ump[i]==0)
                ump[i]=r++;

        // for(auto i: ump)
        //     cout<<i.first<<" "<<i.second<<endl;
        for(int i=0; i<arr.size(); i++)
            arr[i]=ump[arr[i]];

        return arr;
    }
};